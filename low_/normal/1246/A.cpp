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
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, p;

string toBin(int u)
{
    string ret="";
    while (u>0)
    {
        ret+=('0'+(u%2));
        u/=2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int cntBin(int u)
{
    int ret=0;
    // cerr<<u<<" ";
    while (u>0)
    {
        ret+=u%2;
        u/=2;
    }
    // cerr<<ret<<"\n";
    return ret;
}

signed main()
{
#ifdef lowie
    // freopen(FLN".inp", "r", stdin);
    // freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>p;
    for (int ans=1; ans<=32; ans++)
    {
        if (cntBin(n-p*ans)<=ans && ans<=n-p*ans) 
        {
            cout<<ans;
            return 0;
        }
    }

    cout<<-1;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/