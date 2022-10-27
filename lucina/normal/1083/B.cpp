#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
long long n,k;
long long d,ans;
char s[maxn],t[maxn];

int main(){
    scanf("%lld%lld",&n,&k);
    scanf("%s%s",s+1,t+1);
    int pt=1;
    while(s[pt]==t[pt]&&pt<n){
        pt++;
        ans++;
    }
    d=1;
    if(k==1){
        printf("%lld\n",n);
        return 0;
    }
    for(int i=pt;i<=n;i++){
        d=(d-2)*2+2+(s[i]=='a')+(t[i]=='b');
        //printf("%lld\n",d);
        d=min(d,k);
        ans+=d;
    }
    printf("%lld\n",ans);
}