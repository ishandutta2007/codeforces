#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll E=1000000;
const ll D=400000;
ll n,m,k,l,r,d,ans,x,L,R;

int main(){
    cin >> n >> l >> r >> k;
    d=(r-l+n+1)%n; ans=-1;
    for (int i=0;i<=min(n,E);i++)
        if ((k%(n+i)>=d+max(0ll,d-n+i-1))&&(k%(n+i)<=d+min(d,(ll)i))) ans=i;
    //cout << ans << endl;
    if (d==0) d=n;
    if (k>=d&&k<=d*2){
        L=k-d;
        R=k+n+1-2*d;
        if (R>=0&&R>=L&&L<=n) ans=max(ans,min(R,n));
    }
    for (int i=1;i<=min(n,D);i++){
        R=min((k-n*i-d)/i,(k-n*i-2*d+n+1)/(i+1));
        L=max((k-n*i-2*d+i-1)/i,(k-n*i-d+i)/(i+1));
        if (R>=0&&R>=L&&L<=n) ans=max(ans,min(R,n));
    }
    cout << ans << endl;
}