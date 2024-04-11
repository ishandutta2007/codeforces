#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,mod=1e9+7;
int n,m,d[2],a[2],b[2],pre,suf;
char s[maxn];
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
    pre=s[1]-'0';
    suf=s[m]-'0';
    int ma=0; if(suf==pre)ma=1;
    int p=2;
    for(int i=2;i<m;i++){
        pre+=(p*(s[i]-'0'));
        suf<<=1; suf+=(s[m-i+1]-'0');
        if(pre>mod) pre-=mod;
        if(suf>mod) suf-=mod;
       if(pre==suf) ma=i;
       p<<=1; if(p>mod) p-=mod;
    }
    if(m==1) ma=0;
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