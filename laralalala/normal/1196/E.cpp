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
#define MAXN 200005

int ac[MAXN][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        int b,w;
        cin >> b >> w;
        if(b>w*3+1 || w>b*3+1)
        {
            db("NO")
            continue;
        }
        if(b==w)
        {
            db("YES")
            for(int i=1;i<=2*b;i++)
                cout << "2 " << i << '\n';
            continue;
        }
        db("YES")
        if(b<w)
        {
            for(int i=2;i<=2*(b+1);i++)
                cout << "2 " << i << '\n';
            w=w-b-1;
            for(int i=0;i<min(w,b);i++)
                cout << "1 " << i*2+3 << '\n';
            w-=min(w,b);
            for(int i=0;i<min(w,b);i++)
                cout << "3 " << i*2+3 << '\n';
        }
        else
        {
            for(int i=2;i<=2*(w+1);i++)
                cout << "3 " << i << '\n';
            b=b-w-1;
            for(int i=0;i<min(w,b);i++)
                cout << "2 " << i*2+3 << '\n';
            b-=min(w,b);
            for(int i=0;i<min(w,b);i++)
                cout << "4 " << i*2+3 << '\n';
        }
    }

    return 0;
}