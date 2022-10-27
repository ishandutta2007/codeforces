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
int n, A[mn];
bool B[mn];
int mex() {
    for (int i=0; i<=n; i++) B[i] = 0;
    for (int i=0; i<n; i++) B[A[i]] = 1;
    for (int i=0; i<=n; i++) if (B[i] == 0) return i;
}

bool unsorted() {
    for (int i=1; i<n; i++) if (A[i] < A[i-1]) return 1;
    return 0;
}

// main solution goes here:
void execute(int test_number)
{
    cin>>n;
    for (int i=0; i<n; i++) cin>>A[i];
    vector <int> op;
    while (unsorted()) {
        int m = mex();
        if (m == n) {
            int t = 0;
            for (int i=0; i<n; i++) if (A[i] != i) {
                t = i;
                break;
            }
            A[t] = n;
            op.push_back(t+1);
        } else {
            A[m] = m;
            op.push_back(m+1);
        }
    }

    cout<<op.size()<<"\n";
    for (int x:op) cout<<x<<" ";
    cout<<"\n";
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