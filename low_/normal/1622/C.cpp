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
ll n, k;
vector <int> v;
// main solution goes here:
void execute(int test_number)
{
  cin>>n>>k;
  v.assign(n, 0);
  ll sum = 0;
  for (int i=0; i<n; i++) {
    cin>>v[i];
    sum += v[i];
  }

  sort(v.begin(), v.end());
  ll diff = 0;
  ll ans = inf;
  for (int cnt=0; cnt<n; cnt++) { // # of set operation
    ll l = 0, r = 1e10;
    while (r > l) {
      ll mid = (l + r) / 2; // # of decr. operation

      ll newSum = sum - diff - (cnt + 1) * mid;
      // cerr << newSum << "\n";
      if (newSum <= k) r = mid;
      else l = mid + 1;
    }

    ans = min(ans, l + cnt);
    diff += v[n - 1 - cnt] - v[0];
  }

  cout << ans << "\n";
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