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
#define ll long long
#define pii pair <ll, ll>
#define ld long double
#define XX first
#define YY second
#define mattype ll
#define matrix vector <vector <mattype> >

// constants:
const int mn = 5005;
const int mod = 998244353;
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

// debug functions
void debug_vector(string name, vector <ll> v) {
  cerr << name << " @size=" << v.size() << ": [";
  for (int x: v) cerr << x << " ";
  cerr << "]\n";
}

void debug_2d_vector(string name, vector <vector<ll> > v) {

  cerr << name << " @size=" << v.size() << ": {\n";
  for (int i = 0; i < v.size(); i++) {
    cerr << "\t";
    debug_vector(name + "[" + to_string(i) + "]", v[i]);
  }
  cerr << "}\n";
}

// data preprocessing: (e.g.: divisor generating, prime sieve)
void preprocess()
{
  
}

// global variables:
int n, k;
string s;
ll fret[mn][mn], gret[mn][mn];

ll g(int u, int v);

ll f(int u, int v) {
  if (fret[u][v] != -1) return fret[u][v];
  if (u == 0) return fret[u][v] = (v == 0);
  return fret[u][v] = g(u-1, v);
}

ll g(int u, int v) {
  if (gret[u][v] != -1) return gret[u][v];
  if (v == 0) return gret[u][v] = f(u, v);
  return gret[u][v] = (g(u, v-1) + f(u, v)) % mod;
}

// main solution goes here:
void execute(int test_number)
{
  for (int i=0; i<mn; i++) {
    for (int j=0; j<mn; j++) {
      fret[i][j] = gret[i][j] = -1;
    }
  }
  cin>>n>>k>>s;
  vector <ll> v = {};
  int zeroCntr = 0;
  for (auto c: s) {
    if (c == '1') {
      v.push_back(zeroCntr);
      zeroCntr = 0;
    } else zeroCntr ++;
  }
  v.push_back(zeroCntr);
  if (k >= v.size()) {
    cout << 1;
    return;
  }

  ll sum = 0;
  for (int i=0; i<=k; i++) {
    sum += v[i];
  }

  debug_vector("v", v);
  ll ans = f(k+1, sum) % mod;
  for (int i=k+1; i<v.size(); i++) {
    sum += v[i] - v[i-k-1];
    ans = (ans + f(k+1, sum) - f(k, sum - v[i]) + mod) % mod;
  }
  cout << ans;
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