#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
using pli=pair<long long,long long>;
long long a,b;
int k,cnt[1050],r,len,s[22];
long long p[22];
pli dp[22][2][2][1050];


pli ss(int pos,bool z,bool f,int msk){
    if(pos==len) return cnt[msk]<=k?pli(1,0):pli(0,0);
    if(dp[pos][z][f][msk].first>=0)return dp[pos][z][f][msk];
    pli res={0,0};
    for(int i=0;i<10;i++){
        if(f&&i>s[pos])break;
        int nz=z&(i==0);
        if(f&&s[pos]==i){
            pli fuck=ss(pos+1,nz,1,nz?msk:(msk|(1<<i)));
            res.first+=fuck.first;
            res.second+=fuck.second;
            res.second+=((((long long)1*fuck.first*p[pos]%mod)*i)%mod);
        }
        else{
            pli fuck=ss(pos+1,nz,0,nz?msk:(msk|(1<<i)));
            res.first+=fuck.first;
            res.second+=fuck.second;
            res.second+=((((long long)1*fuck.first*p[pos]%mod)*i)%mod);
        }
        res.first%=mod;res.second%=mod;
    }
    return dp[pos][z][f][msk]=res;
}

long long solve(long long x){
    len=0;
    while(x){
        s[len++]=x%10;
        x/=10;
    }
    reverse(s,s+len);
    p[len-1]=1;
    for(int i=len-2;i>=0;i--)p[i]=(p[i+1]*(long long)10)%mod;
    for(int i=0;i<22;i++)for(int j=0;j<2;j++)for(int jj=0;jj<2;jj++)for(int ii=0;ii<1024;ii++)
        dp[i][j][jj][ii]=pli(-1,-1);
    return ss(0,1,1,0).second;
}
int main(){
    scanf("%lld%lld",&a,&b);
    scanf("%d",&k);
    for(int i=1;i<1024;i++){
        r=i;
        while(r){
            cnt[i]+=r&1;r>>=1;
        }
    }
    printf("%lld\n",((solve(b)-solve(a-1))+mod)%mod);
}