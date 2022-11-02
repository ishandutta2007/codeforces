#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

pair<ll, int> mic[202020];
ll c[202020];

const int N=1<<20;
pair<ll, int> st[2*N];

void setm(int i, pair<ll, int> x){
    for (i+=N;i;i/=2){
        st[i]=max(st[i], x);
    }
}
pair<ll, int> getmax(int a, int b){
    a+=N;
    b+=N;
    pair<ll, int> ma={0, 0};
    while (a<=b){
        if (a%2) ma=max(ma, st[a++]);
        if (!(b%2)) ma=max(ma, st[b--]);
        a/=2;
        b/=2;
    }
    return ma;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<pair<ll, ll>, int> > ss(n);
    set<ll> ccs;
    map<ll, int> ccm;
    for (int i=0;i<n;i++){
        cin>>ss[i].F.F>>ss[i].F.S;
        ss[i].S=i+1;
        ccs.insert(ss[i].F.S);
    }
    vector<pair<pair<pair<ll, ll>, ll>, int> >tv(m);
    for (int i=0;i<m;i++){
        cin>>tv[i].F.F.F>>tv[i].F.F.S>>tv[i].F.S;
        tv[i].S=i+1;
        c[i+1]=tv[i].F.S;
        ccs.insert(tv[i].F.F.S);
    }
    int co=0;
    for (ll cc:ccs){
        ccm[cc]=co++;
    }
    sort(ss.begin(), ss.end());
    sort(tv.begin(), tv.end());
    int i2=0;
    pair<ll, int> ma={0, 0};
    for (int i=0;i<m;i++){
        while (i2<n&&ss[i2].F.F<=tv[i].F.F.F){
            ma=max(ma, {ss[i2].F.S, ss[i2].S});
            i2++;
        }
        if (ma.F>tv[i].F.F.F){
            mic[tv[i].S]=max(mic[tv[i].S], {min(ma.F, tv[i].F.F.S)-tv[i].F.F.F, ma.S});
        }
    }
    pair<ll, pair<int, int> > v={0, {0, 0}};
    i2=0;
    for (int i=0;i<n;i++){
        while (i2<m&&tv[i2].F.F.F<=ss[i].F.F){
            setm(ccm[tv[i2].F.F.S], {tv[i2].F.S, tv[i2].S});
            i2++;
        }
        auto asd=getmax(ccm[ss[i].F.S], N-1);
        if (asd.F>0){
            v=max(v, {asd.F*(ss[i].F.S-ss[i].F.F), {ss[i].S, asd.S}});
        }
    }

    for (int i=0;i<n;i++){
        swap(ss[i].F.F, ss[i].F.S);
    }
    for (int i=0;i<m;i++){
        swap(tv[i].F.F.F, tv[i].F.F.S);
    }
    sort(ss.begin(), ss.end());
    sort(tv.begin(), tv.end());
    i2=n-1;
    ma={1e9+10, 0};
    for (int i=m-1;i>=0;i--){
        while (i2>=0&&ss[i2].F.F>=tv[i].F.F.F){
            ma=min(ma, {ss[i2].F.S, ss[i2].S});
            i2--;
        }
        if (ma.F<tv[i].F.F.F){
            mic[tv[i].S]=max(mic[tv[i].S], {tv[i].F.F.F-max(ma.F, tv[i].F.F.S), ma.S});
        }
    }

    for (int i=1;i<=m;i++){
        v=max(v, {mic[i].F*c[i], {mic[i].S, i}});
    }
    cout<<v.F<<endl;
    if (v.F>0){
        cout<<v.S.F<<" "<<v.S.S<<endl;
    }
}