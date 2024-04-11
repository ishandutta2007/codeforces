// 
//  day 998244352

// 998244353  3 998244353=(119<<23)+1 3 inverse -> 332748118 modulo 998244353
// ^ if i want to refer to ntt template later

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define poly vector<int>
const int mxN=125005,alpha=6,mod=998244353,rt=3,ni=332748118;
int n,m,ans[mxN],p[mxN][alpha];
poly wa[alpha],wb[alpha],go;
string s,t;
int bm(int b,int p,int m=mod){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
int pp(int x){
    int ans=1;
    while(ans<=x)ans<<=1;
    return ans;
}
int set_of(int x,int v){
    return p[x][v]==v?v:p[x][v]=set_of(x,p[x][v]);
}
void ntt(poly& dxs,int prim,int lim){ // duo xiang shi, primitive root, limit
    dxs.resize(lim);
    for(int i=0,j=0;i<lim;i++){
        if(i<j)swap(dxs[i],dxs[j]);
        for(int k=lim>>1;(j^=k)<k;k>>=1);
    }
    poly w(lim>>1);
    w[0]=1;
    for(int i=1;i<lim;i<<=1){
        for(int j=1,k=bm(prim,(mod-1)/(i<<1));j<i;j++)w[j]=(w[j-1]*k)%mod;
        for(int j=0;j<lim;j+=(i<<1)){
            for(int k=0;k<i;k++){
                int x=dxs[j+k],y=(dxs[i+j+k]*w[k])%mod;
                dxs[j+k]=(x+y)%mod;
                dxs[i+j+k]=(x-y+mod)%mod;
            }
        }
    }
    if(prim==ni){
        for(int i=0;i<lim;i++)(dxs[i]*=bm(lim,mod-2))%=mod;
    }
}
signed main(){
    cin>>s>>t;
    n=s.length();
    m=t.length();
    int z=pp(n+m-1);
    for(int i=0;i<6;i++){
        wa[i].resize(z);
        wb[i].resize(z);
        for(int j=0;j<n;j++)wa[i][j]=(s[j]=='a'+i);
        for(int j=0;j<m;j++)wb[i][m-j-1]=(t[j]=='a'+i);
        ntt(wa[i],rt,z);
        ntt(wb[i],rt,z);
    }
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<6;j++)p[i][j]=j;
    }
    go.resize(z);
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i!=j){
                for(int k=0;k<z;k++)go[k]=(wa[i][k]*wb[j][k])%mod;
                ntt(go,ni,z);
                for(int k=0;k<n-m+1;k++){
                    if(go[k+m-1]){
                        if(set_of(k,i)!=set_of(k,j)){
                            ans[k]++;
                            p[k][set_of(k,i)]=set_of(k,j);
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n-m+1;i++)cout<<ans[i]<<" ";
}
// 