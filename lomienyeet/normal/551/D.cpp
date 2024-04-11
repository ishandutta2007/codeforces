// my math is so bad its gonna be actually funny to watch myself try and fail from a 3rd person perspective

#include <bits/stdc++.h>
using namespace std;
#define int long long
struct matrix{
    int a[2][2];
};
matrix operator*(matrix x,matrix y){
    matrix ans;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans.a[i][j]=0;
            for(int k=0;k<2;k++)ans.a[i][j]+=x.a[i][k]*y.a[k][j];
        }
    }
    return ans;
}
matrix operator%(matrix mat,int mod){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)mat.a[i][j]%=mod;
    }
    return mat;
}
matrix bm(matrix mat,int p,int m){
    // rare recursive bigmod moment
    if(p==1)return mat%m;
    if(p&1)return (bm(mat,p-1,m)*mat)%m;
    matrix ans=bm(mat,p>>1,m);
    return (ans*ans)%m;
}
int bm(int b,int p,int m){
    int ans=1;
    b%=m;
    while(p){
        if(p&1)(ans*=b)%=m;
        (b*=b)%=m;
        p>>=1;
    }
    return ans;
}
signed main(){
    int n,k,l,m;
    cin>>n>>k>>l>>m;
    if(l<63&&k>=(1ll<<l)){
        cout<<"0\n";
        return 0;
    }
    matrix mat;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)mat.a[i][j]=(!(i&j));
    }
    mat=bm(mat,n+1,m);
    int ans=1,go=bm(2,n,m);
    for(int i=0;i<l;i++){
        int z=(k&1?go-mat.a[0][0]:mat.a[0][0]);
        (ans*=z)%=m;
        k>>=1;
    }
    cout<<(ans+m)%m<<"\n";
}

// is the problem name a cookiezi reference?