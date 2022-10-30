#include<bits/stdc++.h>

using namespace std;

struct cww{cww(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout<<fixed<<setprecision(10);
}
}init;

typedef double D;
typedef long long LL;
#define S 128
int sz=S;
struct M{
    D v[S][S];
}mat[32];

void mat_mul(M &a,M& b,M &c){
    for(int i=0;i<sz;i++)for(int j=0;j<sz;j++)c.v[i][j]=0;

    D sum[4],tmp;
    for(int k=0;k<sz;k++){
        for(int i=0;i<sz;i+=4){
            sum[0]=a.v[i][k];
            sum[1]=a.v[i+1][k];
            sum[2]=a.v[i+2][k];
            sum[3]=a.v[i+3][k];
            for(int j=0;j<sz;j++){
                tmp=b.v[k][j];
                c.v[i][j]+=sum[0]*tmp;
                c.v[i+1][j]+=sum[1]*tmp;
                c.v[i+2][j]+=sum[2]*tmp;
                c.v[i+3][j]+=sum[3]*tmp;
            }
        }
    }
}



int main(){
    LL n;int x;
    cin>>n>>x;
    vector<D> p(x+1),res(sz+1,0);
    res[0]=1;
    for(auto &it:p)cin>>it;

    for(int i=0;i<sz;i++)
        for(int j=0;j<=x;j++){
            mat[0].v[i][i^j]=p[j];
        }
    for(int t=1;t<32;t++)
        mat_mul(mat[t-1],mat[t-1],mat[t]);
    int id=0;
    while(n){
        if(n&1){
            vector<D> nxt(sz,0);
            for(int i=0;i<sz;i++)
                for(int j=0;j<sz;j++)
                    nxt[j]+=res[i]*mat[id].v[i][j];
            swap(res,nxt);
        }
        id++;
        n>>=1;
    }
    cout<<1-res[0]<<endl;
return 0;
}