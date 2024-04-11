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
int n, k;
string str;
int scoring(string s) {
  int score = 0;
  bool prv = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == 'W' && prv) score += 2;
    else if (s[i] == 'W') score += 1, prv = 1;
    else prv = 0;
  }
  return score;
}
// main solution goes here:
void execute(int test_number)
{
  cin>>n>>k;
  cin>>str;
  
  int score = scoring(str);
  if (score == 0) {
    for (int i=0; i<k; i++) str[i] = 'W';
    cout << scoring(str);
  } else {
    vector <pair <pii, pii> > segs;
    // str += 'W';
    char cprv = 'W';
    int p = 0;
    for (int i=0; i<str.size(); i++) {
      if (str[i] == 'L' && cprv == 'W') {
        p = i;
        cprv = 'L';
      } else if (str[i] == 'W' && cprv == 'L') {
        segs.push_back({{(int)(p == 0), i-p}, {p, i-1}});
        cprv = 'W';
      }
    }

    if (cprv == 'L') segs.push_back({{1, n-p}, {p, n-1}});

    sort(segs.begin(), segs.end());
    for (pair <pii, pii> pp: segs) {
      // cerr << pp.XX << " " << pp.YY.XX << " " << pp.YY.YY << "\n";
      if (pp.XX.YY <= k) {
        for (int i = pp.YY.XX; i<= pp.YY.YY; i++) {
          str[i] = 'W';
        }
        k-=pp.XX.YY;
      } else {
        if (pp.YY.XX == 0) {
          for (int i = pp.YY.YY; i > pp.YY.YY - k; i--) {
            str[i] = 'W';
          }
        } else {
          for (int i = pp.YY.XX; i < pp.YY.XX + k; i++) {
            str[i] = 'W';
          }
        }
        k = 0;
      }
    }
    
    // str.pop_back();
    // cerr<<str<<"\n";
    cout<<scoring(str);
  } 
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
// ...or codeforces: https://www.codeforces.com/profile/low_
// ...or linkedIn: https://www.linkedin.com/in/daniel-to-83045a19a/
// I use VS Code. Here's a JSON format for my template: https://pastebin.com/xH2yRdwx