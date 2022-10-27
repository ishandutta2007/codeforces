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
string S;
pii ps[mn];

// main solution goes here:
void execute(int test_number)
{
    cin>>n>>S;
    S=" "+S;
    ps[0]={0, 0};
    for (int i=1; i<=n; i++) 
    {
        if (S[i]=='L') ps[i]={ps[i-1].XX-1, ps[i-1].YY};
        else if (S[i]=='R') ps[i]={ps[i-1].XX+1, ps[i-1].YY};
        else if (S[i]=='U') ps[i]={ps[i-1].XX, ps[i-1].YY+1};
        else ps[i]={ps[i-1].XX, ps[i-1].YY-1};
    }
    map <pii, vector <int> > M={};
    for (int i=0; i<=n; i++) 
    {
        if (M.count(ps[i]))
        {
            M[ps[i]].push_back(i);
        }
        else M[ps[i]]={i};
    }
    pair <int, pii> ans={inf, {inf, inf}};
    for (pair <pii, vector <int> > ppv: M)
    {
        for (int i=1; i<ppv.YY.size(); i++)
        {
            ans=min(ans, {ppv.YY[i]-ppv.YY[i-1], {ppv.YY[i-1]+1, ppv.YY[i]}});
        }
    }

    if (ans.XX==inf) cout<<"-1\n";
    else cout<<ans.YY.XX<<" "<<ans.YY.YY<<"\n";
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