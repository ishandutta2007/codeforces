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
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        set<int> s;
        s.insert(0);
        for(int i=1;i<=sqrt(n)+1;i++)
        {
            int k=n/i;
            s.insert(k);

            int r2=0;
            for(int p=(1<<30);p;p>>=1)
                if(n/(r2+p)>i)
                    r2+=p;
            r2++;
            if(n/r2==i)
                s.insert(i);
        }

        vector<int> v;
        for(auto y : s)
            v.push_back(y);

        sort(v.begin(),v.end());

        db(v.size())
        for(auto y : v)
            cout << y << ' ';
        cout << '\n';
    }

    return 0;
}