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
typedef vector<ll> vi;

const int MAX=1e5+5,INF=1e9+9999;

int n,m;
vi a,b;

ll f(ll x){
    ll res=0;
    vi::iterator it1=a.begin(),it2=b.begin();
    while(it1!=a.end()&&*it1<x){
        res+=x-(*it1);
        it1++;
    }
    while(it2!=b.end()&&*it2>x){
        res+=(*it2)-x;
        it2++;
    }
    return res;
}

void init(void){
    scanf("%d%d",&n,&m);
    ff(i,1,n+m){
        ll x;
        scanf("%I64d",&x);
        if(i<=n) a.pb(x);
        else b.pb(x);
    }
}

void process(void){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<ll>());
    ll lo=0,up=INF;
    while(1){
        ll m1=(up+lo+lo)/3,m2=(up+up+lo)/3;
        if(lo==m1||m1==m2||m2==up) break;
        if(f(m1)>f(m2)) lo=m1;
        else up=m2;
    }
    printf("%I64d",f(lo+up>>1));
}

int main(void){
    init();
    process();
    return 0;
}