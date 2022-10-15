#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e2+5,mod=1e9+7;
struct matrix{
    int a[mxN][mxN];
    matrix operator*(const matrix &mat)const{
        matrix ans;
        for(int i=0;i<mxN;i++){
            for(int j=0;j<mxN;j++){
                ans.a[i][j]=0;
                for(int k=0;k<mxN;k++)(ans.a[i][j]+=(a[i][k]*mat.a[k][j])%mod)%=mod;
            }
        }
        return ans;
    }
};
matrix bm(matrix b,int p){
    if(p==0||p==1)return b;
    if(p&1)return b*bm(b,p-1);
    matrix z=bm(b,p>>1);
    return z*z;
}
signed main(){
    int n,m,k,x;
    cin>>n>>m>>k>>x;
    int freq[mxN]={};
    for(int i=1,z;i<=n;i++){
        cin>>z;
        freq[z]++;
    }
    matrix ans;
    memset(ans.a,0,sizeof ans.a);
    for(int i=0;i<x;i++){
        for(int j=0;j<10;j++)ans.a[i][(i*10+j)%x]+=freq[j];
    }
    ans=bm(ans,m);
    cout<<ans.a[0][k]<<"\n";
}