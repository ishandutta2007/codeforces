#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char s[maxn];
int n,l,r;
long long ans;
bool ok(int i,int j){
    return (i+j+j<=n)&&(s[i]==s[i+j])&(s[i+j]==s[i+j+j]);
}

int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    //the length cannot be greater than 9
    for(int i=1;i<=n;i++){
        int ma=n+10;
        for(int j=i;j<=min(n,i+9);j++){
            for(int k=1;k<=5;k++){
                if(ok(j,k)){
                    ma=min(ma,j+k+k);
                }
            }
        }
        ans+=max(0,n-ma+1);
    }
    printf("%lld\n",ans);
}