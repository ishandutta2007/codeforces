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
#define pii pair <int, int>
#define XX first
#define YY second

// constants:
const int mn = 5005;
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
int n, d;
int c[mn];
vector <int> V[mn];
int ans[mn];
// main solution goes here:
void printAns()
{
    cout<<"YES\n";
    int ptr=1;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<c[i]; j++)
        {
            V[i].push_back(ptr);
            ptr++;
        }
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<V[i].size(); j++) cout<<V[i-1][j/2]<<" ";
    }
    cout<<"\n";
}

void execute(int test_number)
{
    cin>>n>>d;
    for (int i=0; i<n; i++) 
    {
        V[i].clear();
        c[i]=1;
    }
    int h=(n-1)*n/2;
    if (h<d)
    {
        cout<<"NO\n";
        return;
    }
    int ptr=1;
    for (int i=n-1; i>ptr; i--) {
        int t = min(i-ptr, h-d);
        c[i]--;
        c[i-t]++;
        h-=t;
        if (h==d)
        {
            printAns();
            return;
        }

        if (c[ptr]==(1<<ptr)) ptr++;
    }
    cout<<"NO\n";
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