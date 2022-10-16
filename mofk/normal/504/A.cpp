#include<bits/stdc++.h>
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<ii,int> iii;

const int MAX=1e5+5,INF=1e9;
const ll mod=1e9+7,INFLL=1e18;

int n;
queue<int> q;
vii res;
vii R;
vector<ii> v;

void init(void)
{
    cin>>n;
    ff(i,0,n-1)
    {
        ii b;
        cin>>b.fi>>b.se;
        v.pb(b);
        if(b.fi==1) q.push(i);
    }
}

void process(void)
{
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(!v[u].fi) continue;
        int V=v[u].se;
        res.pb(mp(u,V));
        v[u].fi=v[u].se=0;
        v[V].fi--;v[V].se^=u;
        if(v[V].fi==1) q.push(V);
    }
    cout<<res.size()<<endl;
    if(res.size()) ff(i,0,res.size()-1) cout<<res[i].fi<<" "<<res[i].se<<endl;
}

int main(void)
{
    init();
    process();
    return 0;
}