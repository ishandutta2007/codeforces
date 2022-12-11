#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 100000

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        ll n,x,y;
        cin >> n;
        int f[4];
        ll lx,ly,rx,ry;
        lx=ly=-MAXN;
        rx=ry=MAXN;
        for(int i=0;i<n;i++)
        {
             cin >> x >> y;
             for(int j=0;j<4;j++)
                cin >> f[j];
             ll ilx,ily,irx,iry;
             ilx=irx=x;
             ily=iry=y;
             if(f[0])
                ilx=-MAXN;
             if(f[1])
                iry=MAXN;
             if(f[2])
                irx=MAXN;
             if(f[3])
                ily=-MAXN;

            lx=max(lx,ilx);
            rx=min(rx,irx);
            ly=max(ly,ily);
            ry=min(ry,iry);
        }

        if(lx<=rx && ly<=ry)
            cout << 1 << ' ' << lx << ' ' << ly << '\n';
        else
            cout << "0\n";
    }

    return 0;
}