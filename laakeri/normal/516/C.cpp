#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll d[100001];
ll h[100001];

ll n;

ll dist(int a, int b){
    a%=n;
    b%=n;
    if (a==b) return 0;
    if (a<b){
        return d[b]-d[a];
    }
    else{
        return dist(a, n-1)+dist(0, b)+d[n]-d[n-1];
    }
}

const ll N=1<<18;

struct lol{
    ll k,a,b;
};

lol st[2*N];//0 ei avoin, 1 avoin 01 a, 10 b

ll inf=1e16;

ll getk(lol v1, lol v2, ll di){
    ll ret=max(v1.k, v2.k);
    ret=max(ret, v1.a+v2.b+di);
    return ret;
}

ll geta(lol v1, lol v2, ll di){
    ll ret=max(v1.a+di, v2.a);
    return ret;
}

ll getb(lol v1, lol v2, ll di){
    ll ret=max(v1.b, v2.b+di);
    return ret;
}

void init(int i, int l, int r){
    if (l==r){
        st[i].k=-inf;
        st[i].a=h[l%n];
        st[i].b=h[l%n];
    }
    else{
        int m=(l+r)/2;
        init(i*2, l, m);
        init(i*2+1, m+1, r);
        st[i].k=getk(st[i*2], st[i*2+1], dist(m, m+1));
        st[i].a=geta(st[i*2], st[i*2+1], dist(m, r));
        st[i].b=getb(st[i*2], st[i*2+1], dist(l, m+1));
    }
}

lol get(int i, int l, int r, int ql, int qr){
    if (ql>r) return {-inf, -inf, -inf};
    if (qr<l) return {-inf, -inf, -inf};
    if (ql<=l&&r<=qr){
        //cout<<l<<" "<<r<<" "<<st[i].k<<" "<<dist(2, 0)<<" "<<d[n]<<endl;
        return st[i];
    }
    else{
        lol ret;
        int m=(l+r)/2;
        lol a=get(i*2, l, m, ql, qr);
        lol b=get(i*2+1, m+1, r, ql, qr);
        ret.k=getk(a, b, dist(m, m+1));
        ret.a=geta(a, b, dist(m, min(r, qr)));
        ret.b=getb(a, b, dist(max(l, ql), m+1));
        //cout<<l<<" "<<r<<" "<<ret.k<<" "<<a.a<<" "<<a.b<<" "<<b.a<<" "<<b.b<<" "<<dist(m, m+1)<<" "<<m<<endl;
        return ret;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>d[i];
        if (i) d[i]+=d[i-1];
    }
    for (int i=0;i<n;i++){
        cin>>h[i];
        h[i]*=2ll;
    }
    init(1, 0, N-1);
    //cout<<"lol"<<endl;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        if (a<=b){
            //cout<<b+1<<" "<<(a+n-1)<<endl;
            lol v=get(1, 0, N-1, b+1, (a+n-1));
            cout<<v.k<<'\n';
        }
        else{
            //cout<<b+1<<" "<<(a-1)<<endl;
            lol v=get(1, 0, N-1, b+1, (a-1));
            cout<<v.k<<'\n';
        }
    }
}