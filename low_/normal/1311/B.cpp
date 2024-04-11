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
const bool is_multitest = 1;
const bool is_interactive = 0;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// main solution goes here:
int n, m;
int A[105];
bool P[105];
void execute(int test_number)
{
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>A[i];
    int p;
    for (int i=1; i<=m; i++)
    {
        cin>>p;
        P[p]=1;
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<n; j++) if (A[j]>A[j+1] && P[j])
        {
            int temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
        }
    }

    bool b=1;
    for (int i=1; i<n; i++) if (A[i]>A[i+1]) b=0;
    if (b) cout<<"YES\n";
    else cout<<"NO\n";
    for (int i=1; i<=n; i++) P[i]=0;
}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_











// bubble sort the element of the A array using bubble sort and boolean P[i]







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