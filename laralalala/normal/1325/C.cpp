#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 100005

vector<pii> g[MAXN];
int res[MAXN],cont=1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(pii(v,i));
        g[v].push_back(pii(u,i));
    }

    int r=0;
    for(int i=0;i<n;i++)
        if(g[i].size()==1 && !res[g[i][0].second])
        {
            res[g[i][0].second]=cont;
            cont++;
        }

    for(int i=0;i<n-1;i++)
        if(!res[i])
        {
            res[i]=cont;
            cont++;
        }

    for(int i=0;i<n-1;i++)
        cout << res[i]-1 <<  '\n';

    return 0;
}