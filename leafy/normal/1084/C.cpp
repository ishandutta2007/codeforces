#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
char s[100005];
int a[100005];
ll f[100005],ss[100005];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1),cnt=0,num=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='a') cnt++;
        if(s[i]=='b') {if(cnt>0) a[++num]=cnt;cnt=0;}
    }
    if(cnt>0) a[++num]=cnt;
    f[1]=a[1];ss[1]=a[1];ll sum=0;
    for(int i=2;i<=n;i++) {
        f[i]=((a[i]*ss[i-1]%mod)+a[i])%mod;
        ss[i]=(ss[i-1]+f[i])%mod;
    }
    cout<<ss[n];
    return 0;
}