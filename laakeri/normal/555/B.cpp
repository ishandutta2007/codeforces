#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll l[402020];
ll r[402020];

ll c[402020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<pair<ll, ll> > gs;
    vector<pair<ll, pair<ll, ll> > > ts;
    for (int i=0;i<n;i++){
        cin>>l[i]>>r[i];
        if (r[i]<l[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    for (int i=0;i<n-1;i++){
        ll mi=l[i+1]-r[i];
        ll ma=r[i+1]-l[i];
        ts.push_back({mi, {ma, i+1}});
    }
    for (int i=0;i<m;i++){
        ll a;
        cin>>a;
        gs.push_back({a, i+1});
    }
    sort(gs.begin(), gs.end());
    sort(ts.begin(), ts.end());
    vector<pair<ll, ll> > v;
    set<pair<ll, ll> > tt;
    int i2=0;
    for (int i=0;i<m;i++){
        while (i2<(int)ts.size()&&ts[i2].F<=gs[i].F){
            tt.insert({ts[i2].S});
            i2++;
        }
        int f=1;
        while (f&&tt.size()>0){
            f=0;
            if ((*tt.begin()).F<gs[i].F){
                f=1;
                tt.erase(tt.begin());
            }
            else{
                v.push_back({gs[i].S, (*tt.begin()).S});
                tt.erase(tt.begin());
            }
        }
    }
    if ((int)v.size()<n-1){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for (auto vv:v){
        c[vv.S]=vv.F;
    }
    for (int i=1;i<n;i++){
        cout<<c[i]<<" ";
    }
}