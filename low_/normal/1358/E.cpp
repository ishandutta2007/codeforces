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
const int mn = 250005;
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
int A[mn], x;
int m;

class lazy_tree { // this tree do lazy update. for each segment, gets the minimum element of the tree
private:
    int ST[mn*4], lazy[mn*4];
    int M;

    void UPD(int id, int l, int r, int u, int v, int g) {
        if (lazy[id] != 0) {
            ST[id] += lazy[id];
            if (l!=r) {
                lazy[2*id] += lazy[id];
                lazy[2*id+1] += lazy[id];
            }
            lazy[id] = 0;
        }

        if (r<u || l>v) return;
        if (u <= l && r <= v) {
            ST[id] += g;
            if (l!=r) {
                lazy[id*2] += g;
                lazy[id*2+1] += g;
            }
            return;
        }

        int mid = (l+r)/2;
        UPD(id*2, l, mid, u, v, g);
        UPD(id*2+1, mid+1, r, u, v, g);
        ST[id] = min(ST[id*2], ST[id*2+1]);
    }

    int GET(int id, int l, int r, int u, int v) {
        if (lazy[id] != 0) {
            ST[id] += lazy[id];
            if (l!=r) {
                lazy[2*id] += lazy[id];
                lazy[2*id+1] += lazy[id];
            }
            lazy[id] = 0;
        }

        // cerr<<u<<" "<<v<<" "<<l<<" "<<r<<"\n";
        if (r<u || l>v) return inf;
        // cerr<<u<<" "<<v<<" "<<l<<" "<<r<<"\n";
        if (u<=l && r<=v) return ST[id];
        int mid = (l+r)/2;
        int r1 = GET(id*2, l, mid, u, v);
        int r2 = GET(id*2+1, mid+1, r, u, v);
        return min(r1, r2);
    }

public:
    lazy_tree() {
        for (int i=0; i<mn*4; i++) ST[i] = lazy[i] = 0;
    }

    void update(int u, int v, int g) {
        // cerr<<m<<"\n";
        UPD(1, 1, m, u, v, g);
    }

    int get(int u, int v) {
        return GET(1, 1, m, u, v);
    }
} lz1;
// main solution goes here:
void execute(int test_number)
{
    cin>>n;
    m = n/2+n%2;
    for (int i = 1; i <= m; i++) cin>>A[i];
    cin>>x;

    if (x >= 0) {
        int ret = 0;
        for (int i=1; i <= n; i++) {
            if (i<=m) ret += A[i];
            else ret+=x;
        }
        if (ret<=0) cout<<-1;
        else cout<<n;
        return;
    }

    for (int i=m-1; i>0; i--) A[i] += A[i+1];

    int ptr = n - m;
    for (int i=m; i>0; i--) {
        A[i] += ptr*x;
        ptr--;
    }

    

    for (int i=1; i<=m; i++) lz1.update(i, i, A[i]);
    // cerr<<m<<"\n";
    for (int i=m; i>=1; i--) {
        // cerr<<m<<"\n";
        if (lz1.get(1, i) > 0) {
            // cerr<<lz1.get(1, i)<<"\n";
            cout<<n-i+1;
            return;
        }

        lz1.update(1, m, x);       
    }

    cout<<-1;
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