#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

pair<ll, ll> as[100011];

vector<pair<pair<ll, ll>, ll> > add[100011];

ll va[100011];

struct op{
    ll a,b,t,i;
};

bool cmp(op a, op b){
    return (ld)a.a*b.b>(ld)b.a*a.b;
}

vector<op> mu;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k,n,m;
    cin>>k>>n>>m;
    for (int i=1;i<=k;i++){
        cin>>va[i];
    }
    for (int i=0;i<n;i++){
        ll t,s,b;
        cin>>t>>s>>b;
        if (t==1){
            as[s]=max(as[s], {b, i+1});
        }
        if (t==2){
            add[s].push_back({{b, i+1}, 2});
        }
        if (t==3){
            mu.push_back({b, 1, 3, i+1});
        }
    }
    for (int i=1;i<=k;i++){
        if (as[i].F>va[i]){
            add[i].push_back({{as[i].F-va[i], as[i].S}, 1});
        }
        sort(add[i].rbegin(), add[i].rend());
        for (int ii=0;ii<(int)add[i].size();ii++){
            mu.push_back({add[i][ii].F.F+va[i], va[i], add[i][ii].S, add[i][ii].F.S});
            va[i]+=add[i][ii].F.F;
        }
    }
    sort(mu.begin(), mu.end(), cmp);
    vector<pair<ll, ll> > v;
    int l=min((int)mu.size(), m);
    for (int i=0;i<l;i++){
        v.push_back({mu[i].t, mu[i].i});
    }
    cout<<l<<endl;
    sort(v.begin(), v.end());
    for (auto vv:v){
        cout<<vv.S<<" ";
    }
}