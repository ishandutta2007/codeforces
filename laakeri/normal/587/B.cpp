#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int a[1010101];
ll dp[1010101][2][2];

const ll mod=1e9+7;

vector<int> b[1010101];
vector<int> t[1010101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    ll l;
    cin>>n>>l>>k;
    ll ns=l/n;
    ll en=l%n;
    if (en>0) {
        ns++;
    }
    else{
        en=n;
    }
    vector<int> ccv(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
        ccv[i]=a[i];
    }
    sort(ccv.begin(), ccv.end());
    ccv.erase(unique(ccv.begin(), ccv.end()), ccv.end());
    unordered_map<int, int> cc;
    int i2=1;
    for (int c:ccv){
        cc[c]=i2++;
    }
    for (int i=0;i<n;i++){
        a[i]=cc[a[i]];
        if (i<en) {
            dp[a[i]][0][0]++;
            b[a[i]].push_back(i);
        }
        else {
            dp[a[i]][1][0]++;
            t[a[i]].push_back(i);
        }
    }
    ll v=0;
    //cout<<k<<" "<<ns<<" "<<en<<endl;
    for (int i=0;i<min(k, ns);i++){
        int im=i%2;
        int nim=(i+1)%2;
        for (int j=1;j<i2;j++){
            //cout<<i<<" "<<j<<" "<<dp[j][0][im]<<" "<<dp[j][1][im]<<endl;
            v+=dp[j][0][im]*(((ll)(ns-(ll)(i)+mod))%mod);
            v%=mod;
            if ((((ll)(ns-(ll)(i+1)+mod))%mod)>0){
                v+=dp[j][1][im]*(((ll)(ns-(ll)(i+1)+mod))%mod);
                v%=mod;
            }
        }
        ll s=0;
        for (int j=1;j<i2;j++){
            s+=dp[j][0][im];
            s+=dp[j][1][im];
            s%=mod;
            for (int aa:b[j]){
                dp[a[aa]][0][nim]+=s;
                dp[a[aa]][0][nim]%=mod;
            }
            for (int aa:t[j]){
                dp[a[aa]][1][nim]+=s;
                dp[a[aa]][1][nim]%=mod;
            }
        }
        for (int j=1;j<i2;j++){
            dp[j][0][im]=0;
            dp[j][1][im]=0;
        }
    }
    cout<<v<<endl;
}