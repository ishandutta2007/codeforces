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
const int mn = 4005;
const int mod = 1000000007;
const long long inf = 4444444444444444444;
const int sminf = 1111111111;
const bool is_multitest = 1;
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
    
}

// global variables:
int n;
int A[mn];
int dpret[mn][mn];
vector <int> seglen={inf};
bool dp(int i, int k) { // - determine if there's a configuration to give 
// group 1 k elements by the first i segments
    // cerr<<i<<" "<<k<<"\n";
    if (k<0) return 0;
    if (dpret[i][k] != -1) return dpret[i][k];
    if (i==0) return (k==0);

    return dpret[i][k] = (dp(i-1, k) || dp(i-1, k-seglen[i]));
}

// main solution goes here:
void execute(int test_number)
{
    cin>>n;
    n = n*2;
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dpret[i][j] = -1;
    for (int i=1; i<=n; i++) cin>>A[i];
    vector <pii> st = {{inf, n+1}};
    for (int i=n; i>0; i--) {
        while (st.back().XX < A[i]) st.pop_back();
        st.push_back({A[i], i});
    }
    
    seglen = {inf};
    for (int i=1; i<st.size(); i++) seglen.push_back(st[i-1].YY - st[i].YY);
    // for (int i:seglen) cerr<<i<<" ";
    // cerr<<"\n";
    if (dp(seglen.size() - 1, n/2)) cout<<"YES\n";
    else cout<<"NO\n";
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