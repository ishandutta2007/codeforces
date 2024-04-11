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
int n, m, q;
vector <pii> toys;
vector <pii> queries;
vector <int> root;
vector <int> weight;
int getroot(int u) {
  if (u == root[u]) return u;
  return root[u] = getroot(root[u]);
}

void mergeroot(int u, int v) { // v > u
  int x = getroot(u), y = getroot(v);
  if (x == y) return;
  root[x] = y;
  weight[y] += weight[x];
}

vector <int> prefixSum;
int segmentSum(int l, int r) {
  if (l == 0) return prefixSum[r];
  else return prefixSum[r] - prefixSum[l-1];
}

// main solution goes here:
void execute(int test_number)
{
  cin>>n>>m>>q;
  toys.assign(n+m, {0, 0});
  for (int i=0; i<n; i++) {
    cin>>toys[i].XX;
    toys[i].YY = 1;
  }
  for (int i=0; i<m; i++) {
    cin>>toys[i+n].XX;
    toys[i+n].YY = 0;
  }

  sort(toys.begin(), toys.end());
  // 

  queries.assign(q, {0, 0});
  for (int i=0; i<q; i++) {
    cin>>queries[i].XX;
    queries[i].YY = i;
  }


  vector <int> ans(q, 0);
  sort(queries.begin(), queries.end());

  root.assign(m+n, 0);
  weight.assign(m+n, 0);
  for (int i=0; i<m+n; i++) root[i] = i, weight[i] = toys[i].YY;

  prefixSum.assign(m+n, toys[0].XX);
  for (int i=1; i<m+n; i++) prefixSum[i] = prefixSum[i-1] + toys[i].XX;

  int tempRes = 0;
  for (pii x:toys) tempRes += x.XX * x.YY;
  
  deque <pii> mergeOrder;
  for (int i=1; i<toys.size(); i++) {
    mergeOrder.push_back({toys[i].XX - toys[i-1].XX, i - 1});
  }

  sort(mergeOrder.begin(), mergeOrder.end());

  // for (auto merg: mergeOrder) {
  //   cerr << merg.first << " " << merg.second << "\n";
  // }

  for (pii qr: queries) {
    while (!mergeOrder.empty()) {
      pii merg = mergeOrder.front();
      // cerr << merg.first << " " << merg.second << " " << qr.first << "\n";
      if (merg.XX > qr.XX) break;
      mergeOrder.pop_front();

      int ind = merg.YY;
      int x = getroot(ind), y = getroot(ind + 1);
      // cerr << x << " " << y << "\n";
      tempRes -= segmentSum(x - weight[x] + 1, x) + segmentSum(y - weight[y] + 1, y);
      mergeroot(x, y);
      tempRes += segmentSum(y - weight[y] + 1, y);
    }

    ans[qr.YY] = tempRes;
  }

  for (int a: ans) cout << a << "\n";
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