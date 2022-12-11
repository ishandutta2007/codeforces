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
typedef pair<string,int> psi;

vector<psi> s;

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
        s.resize(n);
        for(int i=0;i<n;i++)
        {
            cin >> s[i].first;
            s[i].second = i;
        }

        sort(s.begin(),s.end());

        int res=0;
        for(int i=1;i<n;i++)
        {
            if(s[i].first==s[i-1].first)
            {
                res++;
                for(int j=0;j<10;j++)
                {
                    s[i].first[0]='0'+j;
                    bool ok=1;
                    for(int k=0;k<n;k++)
                        if(s[i].first==s[k].first && i!=k)
                            ok=0;
                    if(ok)
                        break;
                }

                sort(s.begin(),s.end());
                i=0;
            }
        }

        db(res)
        string rs[n];
        for(int i=0;i<n;i++)
            rs[s[i].second]=s[i].first;
        for(int i=0;i<n;i++)
            db(rs[i])
    }

    return 0;
}