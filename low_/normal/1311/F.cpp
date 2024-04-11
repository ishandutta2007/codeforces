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
class fenwick_tree{
public:
    int FW[mn];

    fenwick_tree()
    {
        for (int i=0; i<mn; i++) FW[i]=0;
    }

    int get(int u)
    {
        int ret=0;
        while (u>0)
        {
            ret+=FW[u];
            u-=(u&(-u));
        }
        return ret;
    }

    void update(int u, int g)
    {
        while (u<mn)
        {
            // cerr<<u<<" "<<g<<"\n";
            FW[u]+=g;
            u+=(u&(-u));
        }
    }

    int intervals(int l, int r)
    {
        return get(r)-get(l-1);
    }
} FWcnt, FWsumX;


void preprocess()
{
    
}

// global variables:
int n;
pii xv[mn];
// main solution goes here:
vector <int> vv={-inf};
int bs(int u)
{
    int l=0, r=n;
    while (r>l)
    {
        int mid=(l+r)/2;
        if (vv[mid]<u) l=mid+1;
        else r=mid;
    }
    return l;
}

void execute(int test_number)
{
    cin>>n;
    for (int i=1; i<=n; i++) cin>>xv[i].XX;
    for (int i=1; i<=n; i++)
    {
        cin>>xv[i].YY;
        vv.push_back(xv[i].YY);
    }
    sort(xv+1, xv+n+1);
    sort(vv.begin(), vv.end());

    // cerr<<"run";

    int ans=0;
    for (int i=1; i<=n; i++)
    {
        // cerr<<"run\n";
        ans += FWcnt.get(bs(xv[i].YY))*xv[i].XX - FWsumX.get(bs(xv[i].YY));
        FWcnt.update(bs(xv[i].YY), 1);
        // cerr<<"run\n";
        FWsumX.update(bs(xv[i].YY), xv[i].XX);
    }

    cout<<ans<<"\n";


}
// REMEMBER TO CHOOSE TEST METHODS
// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Solution by low_



















signed main()
{
#ifdef lowie
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
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