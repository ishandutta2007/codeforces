#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf=1e18+10;

ll prv[202020];
ll sfv[202020];
ll a[202020];
int ok[202020];
int okk[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll k;
    cin>>n>>k;
    for (int i=0;i<=n;i++){
        cin>>a[i];
    }
    ok[0]=1;
    for (int i=0;i<=n;i++){
        prv[i+1]=(prv[i]+a[i])/2ll;
        if ((prv[i]+a[i])%2ll==0){
            ok[i+1]=1;
        }
        else{
            break;
        }
    }
    okk[n]=1;
    for (int i=n;i>0;i--){
        if ((sfv[i]+a[i])*2ll>inf||(sfv[i]+a[i])*2ll<-inf){
            break;
        }
        sfv[i-1]=(sfv[i]+a[i])*2ll;
        okk[i-1]=1;
    }
    int v=0;
    for (int i=0;i<=n;i++){
        if (ok[i]&&okk[i]){
            ll ne=sfv[i]+prv[i];
            if (ne<=k&&ne>=-k){
                if (i<n||ne!=0) v++;
            }
        }
    }
    cout<<v<<endl;
}