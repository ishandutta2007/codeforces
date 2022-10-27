#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353 ;
char s[maxn];
int n,a[27][200025];

int main(){
    scanf("%d %s",&n,s+1);
    int id=1;
    for(id=1;s[id]==s[1];id++){
        if(id=='\0')
            break;
    }
    id--;
    int x=id;
    int y=n;
    for(y=n;s[n]==s[y];y--)
        if(y==0)
        break;
    y=n-y;
    long long b;
    long long ans=0;
    if(s[1]==s[n]){
            if(x+y>=n){
                ans=(long long)1*(n+1)*(n);
                ans/=2;
                ans%=mod;
                printf("%lld\n",ans);
                return 0;
            }
            else{
                ans=(long long)1*(x+1)*(y+1);
                ans%=mod;
                printf("%lld\n",ans);
                return 0;
            }
       }
    else{
        printf("%d\n",y+x+1);
        return 0;
    }
}