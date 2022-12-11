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

string s[MAXN];
int d[MAXN],f[26],res;

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return ;

    d[u]+=d[v];
    d[v]=u;
    res--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    res=n;
    for(int i=0;i<n;i++)
        d[i]=-1;
    for(int i=0;i<n;i++)
        cin >> s[i];

    for(int i=0;i<26;i++)
        f[i]=-1;

    for(int i=0;i<n;i++)
    {
        bool mk[26];
        bool mk2[26];
        for(int j=0;j<26;j++)
            mk2[j]=mk[j]=0;
        for(auto y : s[i])
            mk[y-'a']=1;

        vector<int> jo;
        for(int j=0;j<26;j++)
        {
            if(mk[j] && f[j]!=-1)
                jo.push_back(f[j]);
        }
        jo.push_back(i);

        for(int k=0;k<26;k++)
            for(auto y : jo)
                if(f[k]==y || mk[k])
                    mk2[k]=1;
        for(int k=1;k<jo.size();k++)
            join(jo[0],jo[k]);
        for(int j=0;j<26;j++)
            if(mk2[j])
                f[j]=find(i);
    }
    db(res)

    return 0;
}