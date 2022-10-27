#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353 ;
void plusle(int &a,int b){a+=b;if(a>=mod)a-=mod; return;}
void minun(int &a,int b){a-=b; if(a<0)a+=mod; return;}
int add(int a,int b) {a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b) {a-=b;return a<0?a+mod:a;}
int mul(int a,int b) {return (int)((long long)a*b%mod);}
int power(int a,int b) {int res=1;while (b>0) {if (b&1) {res=mul(res,a);}a=mul(a,a);b>>=1;}return res;}
int ans=1,n,fac[maxn];
pair<int,int> b[maxn];
bool cmp(const pair<int,int> &x,const pair<int,int> &y){
    if(x.second==y.second)return x.first<y.first;
    return x.second<y.second;
}
 
int main(){
    scanf("%d",&n);
    fac[0]=1;
    for(int i=1;i<=n+5;i++)
        fac[i]=mul(fac[i-1],i);
    ans=fac[n];
    for(int i=1;i<=n;i++)
        scanf("%d%d",&b[i].first,&b[i].second);
    sort(b+1,b+1+n);
    int f=1,s=1;
    for(int i=1;i<=n;i++){
        int j=i;
        while(b[j].first==b[i].first&&j<=n)j++;
        j--;
        f=mul(f,fac[j-i+1]);
        i=j;
    }
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++){
        int j=i;
        while(b[j].second==b[i].second&&j<=n)j++;
        j--;
        s=mul(s,fac[j-i+1]);
        i=j;
    }
    sort(b+1,b+1+n);
    bool ok=true;
    for(int i=2;i<=n;i++){
        ok&=(b[i].first>=b[i-1].first&&b[i].second>=b[i-1].second);
    }
    int bt=ok;
    if(ok){
        for(int i=1;i<=n;i++){
            int j=i;
            while(b[j]==b[i]&&j<=n)j++;
            j--;
            bt=mul(bt,fac[j-i+1]);
            i=j;
        }
    }
   // cout<<bt<<endl;
    plusle(f,s);
    minun(f,bt);
    minun(ans,f);
    printf("%d\n",ans);
}
/*
    Good Luck
        -Lucina
*/