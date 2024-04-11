#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<ll, ll> > a(n);
    for (int i=0;i<n;i++){
        cin>>a[i].S>>a[i].F;
    }
    ll v=1e17;
    for (ll i=1;i<=1000;i++){
        ll w=0;
        int f=0;
        vector<ll> bm;
        for (int ii=0;ii<n;ii++){
            if (a[ii].F>i){
                if (a[ii].S<=i){
                    w+=a[ii].F;
                    f++;
                }
                else{
                    f=-1;
                    break;
                }
            }
            else{
                w+=a[ii].S;
                if (a[ii].S<=i){
                    bm.push_back(a[ii].F-a[ii].S);
                }
            }
        }
        if (f>=0&&f<=n/2){
            sort(bm.begin(), bm.end());
            for (int i=0;i<bm.size()&&f<n/2&&bm[i]<0;i++){
                f++;
                w+=bm[i];
            }
            v=min(v, w*i);
        }
    }
    cout<<v<<endl;
}