#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,mod=998244353;
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
char s[12];
int p[22],d[11],len[maxn],odd[maxn][11],even[maxn][11],val[maxn][11];
 
int main(){
    scanf("%d",&n);
    p[0]=1;
    for(int i=1;i<=22;i++)
        p[i]=mul(p[i-1],10);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        c=strlen(s);
        reverse(s,s+c);
        d[c]++;
        len[i]=c;
        for(int j=c-1;j>=0;j--){
            val[i][j]=val[i][j+1]+mul(p[j],s[j]-'0');
        }
        int cur=0;
        for(int j=0;j<c;j++){
            even[i][j]=add(j?even[i][j-1]:0,mul(s[j]-'0',p[cur]));
            cur++;
            odd[i][j]=add(j?odd[i][j-1]:0,mul(s[j]-'0',p[cur]));
            cur++;
        }
        }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<len[i];j++){
            plusle(ans,mul(mul(2,d[j]),mul(p[j],val[i][j])));
            plusle(ans,mul(even[i][j-1],d[j]));
            plusle(ans,mul(odd[i][j-1],d[j]));
        }
        for(int j=len[i];j<=10;j++){
            plusle(ans,mul(even[i][len[i]-1],d[j]));
            plusle(ans,mul(odd[i][len[i]-1],d[j]));
        }
    }
 
    printf("%d\n",ans);
 
}