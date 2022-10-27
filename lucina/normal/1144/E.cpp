#include<stdio.h>
const int maxn=2e5+10;
char s[maxn],t[maxn];
int n,c[maxn];

int main(){
    scanf("%d",&n);
    scanf("%s%s",s+1,t+1);
    bool top=false;
    for(int i=n;i>=1;i--){
        c[i]=(s[i]-'a')+(t[i]-'a');
        if(top)c[i]++,top=false;
        if(c[i]>=26)c[i]-=26,top=true;
    }
    if(top)c[0]=1;
    top=false;
    for(int i=0;i<=n;i++){
        if(top)c[i]+=26;
        top=c[i]&1;
        c[i]>>=1;
        }
    for(int i=1;i<=n;i++){
        printf("%c",c[i]+'a');
    }
}