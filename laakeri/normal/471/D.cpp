#include <iostream>

using namespace std;

typedef long long ll;

ll mod=483927387ll;
ll mul=39283543ll;

ll a[200001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,w;
    cin>>n>>w;
    if (w==1){
        cout<<n<<endl;
        return 0;
    }
    for (int i=0;i<n;i++) cin>>a[i];
    ll ed=0;
    ll hh=0;
    ll lolmul=1ll;
    for (int i=0;i<w;i++){
        ll aa;
        cin>>aa;
        if (i>0){
            hh*=mul;
            hh%=mod;
            ll ebin=(aa-ed);
            if (ebin>=0) ebin++;
            hh+=ebin;
            if (hh<0) hh+=mod;
            hh%=mod;
        }
        ed=aa;
        if (i>0) {
            lolmul*=mul;
            lolmul%=mod;
        }
    }
    ll h=0;
    int v=0;
    for (int i=1;i<n;i++){
        h*=mul;
        h%=mod;
        if (i>=w){
            ll lol=(a[i-w+1]-a[i-w]);
            if (lol>=0) lol++;
            if (lol<0) lol+=mod;
            lol%=mod;
            lol*=lolmul;
            lol%=mod;
            h-=lol;
            if (h<0) h+=mod;
            h%=mod;
        }
        ll ebin=(a[i]-a[i-1]);
        if (ebin>=0) ebin++;
        h+=ebin;
        if (h<0) h+=mod;
        h%=mod;;
        if (h==hh) v++;
    }
    cout<<v<<endl;
}