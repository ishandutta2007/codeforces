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
const int mn = 400005;
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
int n, m;
vector <int> dsk1[mn];
int q;
vector <int> dsk2[mn];
int a[mn], b[mn];

// Tree
vector <int> children[mn];
int P[mn], H[mn];
void initiateTree(int u) {
  for (int v: dsk1[u]) if (P[v] == 0) {
    children[u].push_back(v);
    P[v] = u;
    H[v] = H[u] + 1;
  }
  for (int v: children[u]) {
    initiateTree(v);
  }
}

vector <int> findPath(int u, int v) {
  if (H[u] < H[v]) {
    vector <int> res = findPath(v, u);
    reverse(res.begin(), res.end());
    return res;
  }
  vector <int> fromU = {u};
  vector <int> fromV = {v};
  while (H[u] > H[v]) {
    u = P[u];
    fromU.push_back(u);
  }

  if (u == v) return fromU;

  while (P[u] != P[v]) {
    u = P[u], v = P[v];
    fromU.push_back(u);
    fromV.push_back(v);
  }
  fromU.push_back(P[u]);
  while (!fromV.empty()) {
    fromU.push_back(fromV.back());
    fromV.pop_back();
  }
  return fromU;
}

// main solution goes here:
void execute(int test_number)
{
  cin>>n>>m;
  int u, v;
  for (int i=1; i<=m; i++) {
    cin>>u>>v;
    dsk1[u].push_back(v);
    dsk1[v].push_back(u);
  }
  cin>>q;
  for (int i=1; i<=q; i++) {
    cin>>u>>v;
    dsk2[u].push_back(v);
    dsk2[v].push_back(u);
    a[i] = u, b[i] = v;
  }

  int cntOdd = 0;
  for (int i=1; i<=n; i++) {
    if (dsk2[i].size() % 2 == 1) cntOdd ++;
  }

  if (cntOdd > 0) {
    cout << "NO\n" << cntOdd / 2 << "\n";
  } else {
    // Initiate a bfs_tree, find h
    P[1] = -1;
    H[1] = 1;
    initiateTree(1);
    // for (int i=1; i<=n; i++) cerr << i << ": parent " << P[i] << ", height " << H[i] << "\n";
    cout << "YES\n";
    for (int i=1; i<=q; i++) {
      vector <int> ans = findPath(a[i], b[i]);
      cout <<ans.size() <<"\n";
      for (int i: ans) cout << i <<" ";
      cout <<"\n";
    }
  }
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