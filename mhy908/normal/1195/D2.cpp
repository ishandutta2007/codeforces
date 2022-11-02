#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
typedef long long LL;
int n;
LL arr[100010];
LL digit[15][100010], digitsum[15][100010];
LL power[20];
LL ans;
int hidig[15];
int main()
{
    scanf("%lld", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &arr[i]);
    }
    sort(arr+1, arr+n+1);
    for(int i=1; i<=n; i++){
        LL temp=arr[i];
        for(int j=0; j<=11; j++){
            digit[j][i]=temp%10;
            digitsum[j][i]=digitsum[j][i-1]+digit[j][i];
            if(!hidig[j]&&digit[j][i]&&!digit[j][i-1]){
                hidig[j]=i;
                for(int k=j-1; k>=0; k--){
                    if(!hidig[k])hidig[k]=hidig[j];
                    else break;
                }
            }
            temp/=10;
        }
    }
    power[0]=1;
    for(int i=1; i<=19; i++){
        power[i]=power[i-1]*10;
        power[i]%=mod;
    }
    int en=0;
    for(int i=13; i>=0; i--){
        if(hidig[i]&&!en){
            en=i+1;
            hidig[i+1]=n+1;
            break;
        }
    }
    for(int i=1; i<=en; i++){
        for(int j=1; j<=en; j++){
            if(i<j){
                for(int k=0; k<=i-1; k++){
                    ans+=power[2*k+1]*(digitsum[k][hidig[i]-1]-digitsum[k][hidig[i-1]-1])%mod*(hidig[j]-hidig[j-1])%mod;
                    ans%=mod;
                }
                for(int k=0; k<=i-1; k++){
                    ans+=power[2*k]*(digitsum[k][hidig[j]-1]-digitsum[k][hidig[j-1]-1])%mod*(hidig[i]-hidig[i-1])%mod;
                    ans%=mod;
                }
                for(int k=i; k<=j-1; k++){
                    ans+=power[2*(i-1)+(k-i+2)]*(digitsum[k][hidig[j]-1]-digitsum[k][hidig[j-1]-1])%mod*(hidig[i]-hidig[i-1])%mod;
                    ans%=mod;
                }
            }
            else{
                for(int k=0; k<=j-1; k++){
                    ans+=power[2*k+1]*(digitsum[k][hidig[i]-1]-digitsum[k][hidig[i-1]-1])%mod*(hidig[j]-hidig[j-1])%mod;
                    ans%=mod;
                }
                for(int k=0; k<=j-1; k++){
                    ans+=power[2*k]*(digitsum[k][hidig[j]-1]-digitsum[k][hidig[j-1]-1])%mod*(hidig[i]-hidig[i-1])%mod;
                    ans%=mod;
                }
                for(int k=j; k<=i-1; k++){
                    ans+=power[2*(j-1)+(k-j+2)]*(digitsum[k][hidig[i]-1]-digitsum[k][hidig[i-1]-1])%mod*(hidig[j]-hidig[j-1])%mod;
                    ans%=mod;
                }
            }
        }
    }
    printf("%lld", ans);
}