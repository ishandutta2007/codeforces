#include<bits/stdc++.h>
#define ff(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9;
const ll INFLL=1e18;

ll n;

ll f(ll a,ll b)
{
    return a*(b-1+(a-1)/2);
}

void init(void)
{
    cin>>n;
}

void process(void)
{
    vector<ll> res;
    for(ll mult=1;mult<=n+1;mult<<=1)
    {
        ll l=0,r=(ll)1e9+7777;
        while(r-l>1)
        {
            ll m=(l+r)/2;
            ll mid=2*m+1;
            ll cmp=f(mid,mult);
            //cout<<mid*mult<<" "<<cmp<<endl;
            if(cmp==n) {res.pb(mid*mult);break;}
            else if(cmp>-1&&cmp<n) l=m;else r=m;
        }
        if(r-l==1)
        {
            if(f(l,mult)==n) res.pb(l*mult);
            if(f(r,mult)==n) res.pb(r*mult);
        }
        else if(f(l,mult)==n) res.pb(l*mult);
    }
    if(res.empty()) {cout<<-1;return;}
    sort(res.begin(),res.end());
    ff(i,0,res.size()-1) cout<<res[i]<<endl;
}

int main(void)
{
    init();
    process();
    return 0;
}