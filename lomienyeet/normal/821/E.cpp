#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mat vector<vector<int> >
const int mod=1e9+7;
mat multi(mat a,mat b){
    mat res;
    res.resize(a.size());
    for(int i=0;i<a.size();i++){
        res[i].resize(b[0].size(),0);
        for(int j=0;j<b[0].size();j++){
            for(int k=0;k<a[0].size();k++)(res[i][j]+=a[i][k]*b[k][j])%=mod;
        }
    }
    return res;
}
mat bm(mat b,int p,int m=mod){
    mat res;
    res.resize(b.size());
    for(int i=0;i<b.size();i++)res[i].resize(b.size());
    for(int i=0;i<b.size();i++)res[i][i]=1;
    while(p){
        if(p&1)res=multi(res,b);
        b=multi(b,b);
        p>>=1;
    }
    return res;
}
signed main(){
    int n,k,ans[25]={};
    cin>>n>>k;
    ans[1]=1;
    for(int i=1,u,v,w;i<=n;i++){
        cin>>u>>v>>w;
        v=min(v,k);
        mat go(w+3);
        ans[w+2]=0;
        for(int j=0;j<w+3;j++)go[j].assign(w+3,0);
        go[0][0]=go[w+2][w+2]=1;
        for(int j=1;j<w+2;j++)go[j][j-1]=go[j][j]=go[j][j+1]=1;
        go=bm(go,v-u);
        int weeee[25]={};
        for(int a=0;a<w+3;a++){
            for(int b=0;b<w+3;b++)(weeee[a]+=ans[b]*go[a][b])%=mod;
        }
        memcpy(ans,weeee,sizeof ans);
        if(v==k)break;
    }
    cout<<ans[1]<<"\n";
}