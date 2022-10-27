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
// #define int long long
#define pii pair <int, int>
#define XX first
#define YY second

// constants:
const int mn = 20005;
const int mod = 1000000007;
const long long inf = 1111111111;
const bool is_multitest = 1;
const bool is_interactive = 0;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// data preprocessing: (e.g.: divisor generating, prime sieve)
vector <int> divsr[mn];
void preprocess()
{
    for (int i=1; i<mn; i++)
    {
        for (int j=1; j*j<=i; j++) if (i%j==0)
        {
            divsr[i].push_back(j);
            if (j*j<i) divsr[i].push_back(i/j);
        }
    }
}

// global variables:
int a, b, c;
// main solution goes here:
void execute(int test_number)
{
    cin>>a>>b>>c;
    pair <pii, pii> ans={{inf, inf}, {inf, inf}};
    for (int ic=1; ic<mn; ic++) 
    {
        for (int ib:divsr[ic])
        {
            for (int ia:divsr[ib])
            {
                ans=min(ans, {{abs(ia-a)+abs(ib-b)+abs(ic-c), ia}, {ib, ic}});
            }
        }
    }
    cout<<ans.XX.XX<<"\n"<<ans.XX.YY<<" "<<ans.YY.XX<<" "<<ans.YY.YY<<"\n";
}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_



















signed main()
{
#ifdef lowie
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
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