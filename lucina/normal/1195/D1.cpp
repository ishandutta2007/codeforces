#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10,mod=998244353;
void plusle(int &a,int b){
    a+=b;if(a>=mod)a-=mod; return;
}
void minun(int &a,int b){
    a-=b; if(a<0)a+=mod; return;
}
int add(int a,int b) {
  a+=b;
  return a>=mod?a-mod:a;
}
int sub(int a,int b) {
  a-=b;
  return a<0?a+mod:a;
}
int mul(int a,int b) {
  return (int)((long long)a*b%mod);
}
int n,x,c,y;
char s[maxn][50];
int p[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]);
        if(c==0)c=strlen(s[i]);
        reverse(s[i],s[i]+c);
    }
    p[0]=1;
    for(int i=1;i<=200005;i++)
        p[i]=mul(p[i-1],10);
    int ans=0;
    for(int i=1;i<=n;i++){
        x=0,y=0;
        int cur=0;
        for(int j=0;j<c;j++){
            plusle(x,mul(s[i][j]-'0',p[cur]));
            cur++;
            plusle(y,mul(s[i][j]-'0',p[cur]));
            cur++;
        }
       /// cout<<x<<' '<<y<<endl;
        plusle(ans,add(mul(y,n),mul(x,n)));
    }
    printf("%d\n",ans);

}
/*
    Good Luck
        -Lucina
*/