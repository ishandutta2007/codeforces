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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while(q--)
    {
        ll n,k,x;
        cin >> n >> k;
        ll ac=0;
        ll dif=0;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            if(((ac&1)!=((ac+x)&1)) && k>1)
            {
                res.push_back(i+1);
                k--;
                dif++;
            }
            ac+=x;
        }
        if((dif&1)!=(ac&1))
        {
            db("YES")
            for(auto y : res)
                cout << y << ' ';
            cout << n;
            cout << '\n';
        }
        else
            db("NO")
    }

    return 0;
}