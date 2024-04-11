#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef unsigned long long ll;

ll ha1[1010101];
ll ha2[1010101];
ll mod=1e9+7;
ll ke=129347;
ll kk1[1010101];
ll kk2[1010101];

int n;

int eq(int a1, int a2, int b1, int b2){
    if (a2<a1) return 1;
    if (b2<b1) return 1;
    if (b2>=n||a2>=n) return 0;
    ll h1=ha1[a2];
    ll h1m=ha2[a2];
    if (a1>0) {
        h1-=ha1[a1-1]*kk1[a2-a1+1];
        h1m+=(mod-((ha2[a1-1]*kk2[a2-a1+1])%mod))%mod;
        h1m%=mod;
    }
    ll h2=ha1[b2];
    //cout<<h2<<endl;
    ll h2m=ha2[b2];
    if (b1>0) {
        h2-=ha1[b1-1]*kk1[b2-b1+1];
        //cout<<ha1[b1-1]*kk1[b2-b1+1]<<endl;
        //cout<<h2<<endl;
        h2m+=(mod-((ha2[b1-1]*kk2[b2-b1+1])%mod))%mod;
        h2m%=mod;
    }
    return h1==h2&&h2m==h1m;
}

const int N=1<<20;
int st[2*N];

void setv(int a, int b){
    a+=N;
    b+=N;
    while(a<=b){
        if (a%2) st[a++]=1;
        if (!(b%2)) st[b--]=1;
        a/=2;
        b/=2;
    }
}
int getv(int i){
    int m=0;
    for(i+=N;i;i/=2){
        m=max(m, st[i]);
    }
    return m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>n>>k;
    string s;
    cin>>s;
    kk1[0]=1;
    kk2[0]=1;
    for (int i=0;i<n;i++){
        if (i) kk1[i]=kk1[i-1]*ke;
        if (i) kk2[i]=kk2[i-1]*ke;
        kk2[i]%=mod;
        ha1[i]=ha1[i-1]*ke+(ll)(1+s[i]-'a');
        ha2[i]=ha2[i-1]*ke+(ll)(1+s[i]-'a');
        ha2[i]%=mod;
    }
    for (int p=1;p<=n;p++){
        int f=0;
        for (int i=0;i<k;i++){
            if (!eq(0, p-1, i*p, i*p+p-1)){
                f=1;
                break;
            }
        }
        if (!f){
            int mi=0;
            int ma=p;
            while (mi<=ma){
                int m=(mi+ma)/2;
                if (eq(0, m-1, p*k, p*k-1+m)){
                    mi=m+1;
                }
                else{
                    ma=m-1;
                }
            }
            setv(p*k-1, p*k-1+ma);
        }
    }
    string v;
    for (int i=0;i<n;i++){
        if (getv(i)) v+='1';
        else v+='0';
    }
    cout<<v<<endl;
}