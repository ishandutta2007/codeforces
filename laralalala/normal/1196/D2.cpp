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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        for(int i=0;i<n;i++)
        {
            int t=0;
            if(s[i]=='G')
                t=1;
            else if(s[i]=='B')
                t=2;
            ac[i+1][0]=ac[i][0]+1;
            ac[i+1][1]=ac[i][1]+1;
            ac[i+1][2]=ac[i][2]+1;
            ac[i+1][(t-(i%3)+3)%3]--;
        }

        ll res=n;
        for(int i=0;i<=n-k;i++)
        {
            ll v1,v2,v3;
            v1=ac[i+k][0]-ac[i][0];
            v2=ac[i+k][1]-ac[i][1];
            v3=ac[i+k][2]-ac[i][2];
            res=min(res,min(v1,min(v2,v3)));
        }
        db(res)
    }

    return 0;
}