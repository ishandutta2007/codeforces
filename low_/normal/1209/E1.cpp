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

vector <pair <int, pii> > V;
int n, m;

bool check(pair <int, pii> p1, pair <int, pii> p2, pair <int, pii> p3, pair <int, pii> p4)
{
    deque <int> t1={p1.YY.YY, p2.YY.YY, p3.YY.YY, p4.YY.YY};
    sort(t1.begin(), t1.end());
    if (!(t1[1]==t1[0] && t1[2]==t1[3] && t1[0]!=t1[3])) return 0;
    deque <pii> t2={{p1.YY.YY, p1.YY.XX}, {p2.YY.YY, p2.YY.XX}, {p3.YY.YY, p3.YY.XX}, {p4.YY.YY, p4.YY.XX}};
    sort(t2.begin(), t2.end());
    t1={t2[0].YY, t2[1].YY, t2[2].YY, t2[3].YY};
    int a1=(t1[0]+t1[1])%2, a2=(t1[2]+t1[3])%2;
    if ((a1+a2)%2==1) return 1;
    return 0;
}

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        V.clear();
        int x;
        for (int i=1; i<=n*m; i++)
        {
            cin>>x;
            V.push_back({x, {(i-1)/m+1, (i-1)%m+1}});
        }
        sort(V.begin(), V.end());
        if (n==4)
        {
            int ans=-inf;
            for (int i1=0; i1<m*n-2; i1++) for (int i2=i1+1; i2<m*n-2; i2++) if (!check(V.back(), V[m*n-2], V[i1], V[i2])) 
                    ans=max(ans, V.back().XX+V[i1].XX+V[i2].XX+V[m*n-2].XX);
            cout<<ans<<"\n";
        }
        else 
        {
            int ans=0;
            for (int i=1; i<=n; i++) ans+=V[m*n-i].XX;
            cout<<ans<<"\n";
        }
        

    }

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/