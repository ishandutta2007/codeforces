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

// constants://
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
int n;
vector <int> A;
vector <vector <int> > ans;
int getpos(int k) {
  for (int i=0; i<n; i++) if (A[i] == k) {
    return i;
  }
  return 0;
}
void permutate(vector <int> V) {
  
  vector <int> v1 = {};
  for (int x: V) if (x !=0) v1.push_back(x);
  if (v1.size() >= 2) ans.push_back(v1);
  vector <int> A1 = {};
  while (!v1.empty()) {
    int x = v1.back();
    v1.pop_back();
    vector <int> newv = {};
    for (int i=0; i<x; i++) {
      newv.push_back(A.back());
      A.pop_back();
    }
    while (!newv.empty()) {
      A1.push_back(newv.back());
      newv.pop_back();
    }
  }
  A = A1;
}
// main solution goes here:
void execute(int test_number)
{
  cin>>n;
  A.assign(n, 0);
  for (int i=0; i<n; i++) cin>>A[i];
  if (n == 1) {
    cout<<0;
    return;
  }
  // cout<<n<<"\n";
  if (n%2==0) {
    vector <int> chg = {getpos(1) + 1, n - getpos(1) - 1};
    permutate(chg);
    for (int i=2; i<=n; i++) {
      if (i%2 == 0) {
        int k = getpos(i);
        if (k == 0) chg = {n - i + 1};
        else chg = {k, n-(i-1)-k};
        for (int j = 1; j<i; j++) chg.push_back(1);
      } else {
        int k = getpos(i);
        chg = {};
        for (int j=1; j<i; j++) chg.push_back(1);
        if (k == n-1) chg.push_back(n - (i-1));
        else {
          chg.push_back(k - i + 2);
          chg.push_back(n - 1 - k);
        }
      }
      permutate(chg);
    }
  } else {
    vector <int> chg = {getpos(1), n - getpos(1)};
    permutate(chg);
    for (int i=2; i<=n; i++) {
      if (i%2 == 0) {
        int k = getpos(i);
        chg = {};
        for (int j=1; j<i; j++) chg.push_back(1);
        if (k == n-1) chg.push_back(n - (i-1));
        else {
          chg.push_back(k - i + 2);
          chg.push_back(n - 1 - k);
        }
      } else {
        int k = getpos(i);
        if (k == 0) chg = {n - i + 1};
        else chg = {k, n-(i-1)-k};
        for (int j = 1; j<i; j++) chg.push_back(1);
      }
      permutate(chg);
    }
  }
  cout<<ans.size()<<"\n";
  for (vector <int> v: ans) {
    cout<<v.size()<<" ";
    for (int x: v) cout<<x<<" ";
    cout<<"\n";
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