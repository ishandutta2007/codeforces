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
  
}

// global variables:
int r, n;
vector <int> t, x, y;
// main solution goes here:
void execute(int test_number)
{
  cin>>r>>n;
  t.assign(n+1, 0);
  x.assign(n+1, 1);
  y.assign(n+1, 1);
  for (int i=1; i<=n; i++) cin>>t[i]>>x[i]>>y[i];
  vector <int> f(n+1, -inf), maxf(n+1, 0);
  f[0] = 0;

  for (int i=1; i<=n; i++) {
    if (i >= 2*r) f[i] = maxf[i-2*r] + 1;
    for (int j=i-1; j>=max(0ll, i-2*r); j--) {
      if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > t[i] - t[j]) continue;
      f[i] = max(f[i], f[j] + 1);
    }
    if (f[i] == 0) f[i] = -inf;
    maxf[i] = max(maxf[i-1], f[i]);
  }

  cout<<maxf[n];
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
// ...or codeforces: https://www.codeforces.com/profile/low_
// ...or linkedIn: https://www.linkedin.com/in/daniel-to-83045a19a/
// I use VS Code. Here's a JSON format for my template: https://pastebin.com/xH2yRdwx