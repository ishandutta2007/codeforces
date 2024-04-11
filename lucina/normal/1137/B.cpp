#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,mod=1e9+7;
int n,m,d[2],a[2],b[2],pre[maxn],suf[maxn],p2[maxn];
char s[maxn];
bool used[maxn];
void finish(){
    while(a[1]--)printf("1");
    while(a[0]--)printf("0");
    exit(0);
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        a[s[i]-'0']++;
    scanf("%s",s+1);
    m=strlen(s+1);
    p2[0]=1;
    for(int i=1;i<=m+3;i++){
        p2[i]=p2[i-1]<<1;
        if(p2[i]>mod) p2[i]-=mod;
    }
    pre[1]=s[1]-'0';
    suf[1]=s[m]-'0';
    for(int i=2;i<=m;i++){
        pre[i]=pre[i-1]+(p2[i-1]*(s[i]-'0'));
        suf[i]=(suf[i-1]<<1)+(s[m-i+1]-'0');
        if(pre[i]>mod) pre[i]-=mod;
        if(suf[i]>mod) suf[i]-=mod;
    }
    int ma=0;
    for(int i=1;i<m;i++){
        if(pre[i]==suf[i])
            ma=i;
    }
    for(int i=1;i<=m;i++){
        d[(s[i]-'0')]++;
    }
    for(int i=1+ma;i<=m;i++){
        b[s[i]-'0']++;
    }
    if(a[1]>=d[1]&&a[0]>=d[0]){
        printf("%s",s+1);
        a[1]-=d[1],a[0]-=d[0];
    }
    else{
        finish();
    }
    while(true){
        if(a[1]>=b[1]&&a[0]>=b[0]){
            for(int i=1+ma;i<=m;i++){
                printf("%c",s[i]);
            }
            a[1]-=b[1],a[0]-=b[0];
        }
        else{
            finish();
        }
    }
}