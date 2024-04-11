#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define pii pair <int, int>
#define XX first
#define YY second

// constants:
const int mn = 200005;
const int mod = 1000000007;
const long long inf = 4444444444444444444;
const int sminf = 1111111111;
const bool is_multitest = 0;
const bool is_interactive = 0;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// data preprocessing: (e.g.: divisor generating, prime sieve)
void preprocess()
{
    srand(time(0));
}

// global variables:
int n, A[mn];
int rand_bw(int l, int r)
{
    int ret=rand();
    ret=(ret<<15)+rand();
    ret=(ret<<15)+rand();
    ret=(ret<<15)+rand();
    return ret%(r-l+1)+l;
}

int find_diff_for_prime(int p)
{
    int ret=0;
    for (int i=1; i<=n; i++) 
    {
        if (A[i]<p) ret+=p-A[i];
        else ret+=min(p-A[i]%p, A[i]%p);
    }
    // cerr<<"find diff "<<p<<" "<<ret<<"\n";
    return ret;
}

int find_diff_for_element(int u)
{
    int ret=inf;
    for (int i=2; i*i<=u; i++) if (u%i==0) 
    {
        while (u%i==0) u/=i;
        ret=min(ret, find_diff_for_prime(i));
    }
    if (u>1) ret=min(ret, find_diff_for_prime(u));
    return ret;
}
// main solution goes here:
void execute(int test_number)
{
    cin>>n;
    for (int i=1; i<=n; i++) cin>>A[i];

    int ans=0;
    for (int i=1; i<=n; i++) ans+=A[i]%2;

    for (int j=0; j<20; j++)
    {
        int r=rand_bw(1, n);
        // cerr<<r<<"\n";
        ans=min(ans, find_diff_for_element(A[r]));
        ans=min(ans, find_diff_for_element(A[r]+1));
        ans=min(ans, find_diff_for_element(A[r]-1));
        // cerr<<r<<" "<<ans<<"\n";
    }
    cout<<ans;
}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_



















signed main()
{
#ifdef lowie
    if (!is_interactive)
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
#else
    if (input_from_file) freopen(filename"."in_extension, "r", stdin);
    if (output_to_file) freopen(filename"."out_extension, "w", stdout);
#endif
    if (!is_interactive)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    preprocess();
    int ntest;
    if (is_multitest) cin >> ntest;
    else ntest = 1;

    for (int testno = 1; testno <= ntest; testno++)
    // use for instead of while to serve facebook hacker cup test format
    {
        execute(testno); // only start coding in this function, not in main
    }
}
// Template by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/