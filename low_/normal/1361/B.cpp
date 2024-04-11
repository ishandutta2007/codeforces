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
const int mn = 1000005;
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
int n, p;
int k[mn];
deque <int> A, B;
int countB[mn];

int powmod(int u, int v) {
    if (v==0) return 1;
    int mid = powmod(u, v/2);
    mid = (mid*mid)%mod;
    if (v%2==0) return mid;
    else return (mid*u)%mod;
}
// main solution goes here:
void execute(int test_number)
{
    A.clear(), B.clear();
    cin>>n>>p;
    for (int i=1; i<=n; i++) cin>>k[i];
    if (p==1) {
        cout<<n%2<<"\n";
        return;
    }

    sort(k+1, k+n+1);
    reverse(k+1, k+n+1);
    for (int i=1; i<=n; i++) {
        while (!A.empty() && !B.empty()) {
            if (A.front() != B.front()) break;
            countB[B[0]] --;
            A.pop_front(), B.pop_front();
        }
        
        if (A.empty()) A.push_back(k[i]);
        else {
            int l = k[i];
            countB[l] ++;
            B.push_back(l);
            while (countB[l] >= p) {
                for (int i =0; i<p; i++) B.pop_back();
                countB[l] = 0;
                l++;
                countB[l]++;
                B.push_back(l);
            }
        }
    }

    int ansa=0, ansb=0;
    for (int x:A) ansa = (ansa+powmod(p, x))%mod;
    for (int x:B) {
        ansb = (ansb+powmod(p, x))%mod;
        countB[x] --;
    }
    int ans = (ansa-ansb+mod)%mod;
    cerr<<powmod(2, 1e6)<<"\n";
    cout<<ans<<"\n";
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