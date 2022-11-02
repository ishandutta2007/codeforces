#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h,q;
    cin>>h>>q;
    ll N=(1ll<<(ll)(h-1));
    vector<pair<ll, int> > lol;
    ll a=N;
    ll b=N*2ll-1ll;
    for (int i=0;i<q;i++){
        ll l,r;
        int aa;
        cin>>l>>l>>r>>aa;
        while (l<N){
            l*=2ll;
            r*=2ll;
            r++;
        }
        if (aa==1){
            a=max(a, l);
            b=min(b, r);
        }
        else{
            lol.push_back({l, 1});
            lol.push_back({r+1, -1});
        }
    }
    lol.push_back({a, 0});
    lol.push_back({b+1, 0});
    if (b<a){
        cout<<"Game cheated!"<<endl;
        return 0;
    }
    ll vs=0;
    ll v=0;
    sort(lol.begin(), lol.end());
    int k=0;
    for (int i=0;i<(int)lol.size();i++){
        k+=lol[i].S;
        if (k==0){
            if (lol[i].F>=a&&lol[i].F<=b){
                ll sz=lol[i+1].F-lol[i].F;
                vs+=sz;
                if (sz>0){
                    v=lol[i].F;
                }
            }
        }
    }
    if (vs>1){
        cout<<"Data not sufficient!"<<endl;
    }
    else if(vs==0){
        cout<<"Game cheated!"<<endl;
    }
    else{
        cout<<v<<endl;
    }
}