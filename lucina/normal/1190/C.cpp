#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k,pre,suf,r[2],l[2];
char b[maxn];


int main(){
    scanf("%d%d%s",&n,&k,b+1);
    for(int i=1;i<=n;i++){
        pre+=b[i]-'0';
        if(pre==i)l[1]=i;
        if(pre==0)l[0]=i;
    }
    for(int i=n;i>=1;i--){
        suf+=b[i]-'0';
        if(suf==0)r[0]=n-i+1;
        if(suf==(n-i+1))r[1]=n-i+1;
    }
    if(max(r[0]+l[0],r[1]+l[1])>=n-k)return !printf("tokitsukaze");
    bool quailty=true;
    quailty&=(k*2>=n&&k!=1);
    for(int i=2;i<=n-k-1;i++){
        quailty&=(b[i]==b[i-1]&&b[n-i+1]==b[n-i+2]);
    }
    quailty&=(b[n-k-1]!=b[n-k]&&b[k+1]!=b[k+2]&&b[n]!=b[1]);
    printf(quailty?"quailty\n":"once again\n");
}