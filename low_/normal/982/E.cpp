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
#define mn 1000005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, m, x, y, vx, vy;
vector <pii> V;

int rand_bw(int l, int r)
{
    int rnd=rand();
    rnd=(rnd<<15)+rand();
    rnd=(rnd<<15)+rand();
    rnd=(rnd<<15)+rand();
    return rnd%(r-l+1)+l;
}

int BS(int u)
{
    int l=0, r=V.size()-1;
    while (r>l)
    {
        int mid=(l+r)/2;
        if (V[mid].XX<u) l=mid+1;
        else r=mid;
    }
    if (V[l].XX==u) return V[l].YY;
    else return -1;
}

int GCD(int u, int v)
{
    if (v==0) return u;
    return GCD(v, u%v);
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

    srand(time(0));

    cin>>n>>m>>x>>y>>vx>>vy;

    if (vx==0)
    {
        int ansx, ansy;
        if (vy==1) ansy=m;
        else ansy=0;

        if (x==n) ansx=n;
        else if (x==0) ansx=0;
        else 
        {
            cout<<"-1";
            return 0;
        }

        cout<<ansx<<" "<<ansy;
    }
    else if (vy==0)
    {
        int ansx, ansy;
        if (vx==1) ansx=m;
        else ansx=0;

        if (y==m) ansy=m;
        else if (y==0) ansy=0;
        else 
        {
            cout<<"-1";
            return 0;
        }
        cout<<ansx<<" "<<ansy;
    }
    else
    {
        if (vx==-1) x=n-x;
        if (vy==-1) y=m-y;
        for (int i=0; i*i<=n; i++) V.push_back({(i*m)%n, i});
        sort(V.begin(), V.end());
        int H=x-y;
        
        int cnt=0;
        while (cnt++<mn)
        {
            int nn=n/GCD(n, m);
            int Y=rand_bw(1, nn);
            int t=(H+Y*m)%n;
            if (t==0)
            {
                int X=(H+Y*m)/n;
                cerr<<X<<" "<<Y<<"...\n";
                int ans1=(X%2)*n;
                int ans2=(Y%2)*m;

                if (vx==-1) ans1=n-ans1;
                if (vy==-1) ans2=m-ans2;

                cout<<ans1<<" "<<ans2;
                return 0;
            }

            int c=BS(n-t);
            if (c==-1) continue;
            Y=Y+c;
            if (Y>nn) Y-=nn;
            int X=(H+Y*m)/n;
            int ans1=(X%2)*n;
            int ans2=(Y%2)*m;

            if (vx==-1) ans1=n-ans1;
            if (vy==-1) ans2=m-ans2;
            cerr<<X<<" "<<Y<<"\n";
            cout<<ans1<<" "<<ans2;
            return 0;
            break;    
        }
        cout<<-1;
    }
    
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/