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
const int mn = 105;
const int mod = 1000000007;
const long long inf = 4444444444444444444;
const int sminf = 1111111111;
const bool is_multitest = 0;
const bool is_interactive = 1;

// i/o methods:
const bool input_from_file = 0;
const bool output_to_file = 0;
#define filename ""
#define in_extension "inp"
#define out_extension "out"

// data preprocessing: (e.g.: divisor generating, prime sieve)
int fact[mn];
void preprocess()
{
fact[0] = 1;
for (int i=1; i<mn; i++) fact[i] = fact[i-1] * i;
}

int C(int u, int v) {
int ret = 1;
for (int i = 1; i <= v; i++) ret = (ret*(u-i+1)/i);
return ret;
}

// global variables:
int n;
int A[mn][mn];
int minpath(int x, int y, int u, int v) {
int ret = 0;
for (int i=x; i<=u; i++) ret += A[i][y];
for (int i=y+1; i<=v; i++) ret += A[u][i];
return ret;
}

int maxpath(int x, int y, int u, int v) {
int ret = 0;
for (int i=y; i<=v; i++) ret += A[x][i];
for (int i=x+1; i<=u; i++) ret += A[i][v];
return ret;
}

// main solution goes here:
void execute(int test_number)
{
cin>>n;
vector <pii> V={{1, 1}};
for (int i=n-1; i>0; i--) {
for (int j=2; j<=n; j++) V.push_back({i, j});
}

for (int i=1; i<V.size(); i++) {
int x = V[i].XX, y = V[i].YY;
int u = V[i-1].XX, v = V[i-1].YY;
A[x][y] = minpath(1, 1, u, v) + maxpath(u+1, v, n, n) - minpath(1, 1, x, y-1) - minpath(x+1, y, n, n) + 1;
}

// cerr<<minpath(1, 1, 3, 4);

for (int i=1; i<=n; i++) {
for (int j=1; j<=n; j++) cout<<A[i][j]<<" ";
cout<<"\n";
}
cout.flush();
int q;
cin>>q;
while (q--) {
int ux;
cin>>ux;
int cd = n-1, cr = n-1;
string ans = "";
int cur_ind = 0;
for (int i=0; i<n+n-2; i++) {
// cerr<<cd<<" "<<cr<<"\n";
if (cd == 0) {
ans.push_back('R');
cr--;
}
else if (ux >= cur_ind + C(cd+cr-1, cd-1)) {
ans.push_back('R');
cur_ind += C(cd+cr-1, cd-1);
cr--;
} else {
ans.push_back('D');
cd--;
}
}
// cerr<<"HERE";

int x = 1, y = 1;
cout<<"1 1\n";
for (char c: ans) {
if (c=='D') x++;
else y++;
cout<<x<<" "<<y<<"\n";
}
cout.flush();
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
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/