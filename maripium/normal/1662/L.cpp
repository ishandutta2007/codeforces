#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF= 1LL<<52;
const int MAXN = 2e5+9;

struct node{
    int s,e,m;
    ll v;
    node *l,*r;
    node(int s,int e):s(s),e(e),m((s+e)/2),v(-INF){
        if(s==e)return;
        l=new node(s,m);
        r=new node(m+1,e);
    }
    ll qu(int x,int y){
        if(s==x&&e==y)return v;
        if(x>m)return r->qu(x,y);
        if(y<=m)return l->qu(x,y);
        return max(l->qu(x,m),r->qu(m+1,y));
    }
    void up(int x,ll uv){
        if(s==e){
            v = max(v, uv);return;
        }
        if(x>m)r->up(x,uv);
        else l->up(x,uv);
        v = max(l->v,r->v); 
    }
} *root;

ll t[MAXN],a[MAXN];
pll p[MAXN];
ll dp[MAXN];
vector<ll> dc;

int main(){
    int n; ll v;
    cin >> n >>v;
    for(int i=1;i<=n;i++)cin >>t[i];
    for(int i=1;i<=n;i++)cin >>a[i];
    for(int i=0;i<=n;i++){
        p[i] = {a[i]+v*t[i], -(a[i]-v*t[i])};//beware 2nd coordinate is negated!
        dc.push_back(-(a[i]-v*t[i]));
    }
    pll p0;
    sort(dc.begin(),dc.end());
    dc.resize(unique(dc.begin(),dc.end())-dc.begin());
    for(int i=0;i<=n;i++){
        p[i].S = lower_bound(dc.begin(),dc.end(),p[i].S)-dc.begin();
        if(i==0)p0=p[0];
    }
    sort(p,p+n+1);
    /*for(int i=0;i<=n;i++){
        cout << p[i].F<< ' ' << p[i].S << endl;
    }*/
    root = new node(0,n);
    ll ans = 0;
    bool has0=0;
    for(int i=0;i<=n;i++){
        if(!has0&&p[i]!=p0)continue;
        if(p[i]==p0){
            dp[i]=0;
            root->up(p[i].S,0);
            has0=1;
            //cout << i << " FOUND p0" << endl;
            continue;
        }
        int y = p[i].S;
        dp[i] = root->qu(0,y)+1;
        //cout << dp[i] << endl;
        root->up(y,dp[i]);
        ans = max(ans,dp[i]);
    }
    cout << ans;
}