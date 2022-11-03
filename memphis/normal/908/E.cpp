#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <bitset>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define fi first
#define se second

using namespace std;

typedef long long ll;

const int N=1005;
const int P=1000000007;

ll a[N];
int B[N],m,n,C[N][N];
bool v[N];
char s[N][N];

int main(){
    rep(i,0,1000) rep(j,0,i)
        C[i][j]=(j==0?1:(C[i-1][j]+C[i-1][j-1])%P);
    B[0]=1;
    B[1]=1;
    rep(i,2,1000) rep(k,0,i-1) B[i]=(B[i]+(ll)C[i-1][k]*B[k]%P)%P;

    //rep(i,1,100) printf("%d ",B[i]);

    scanf("%d%d",&m,&n);
    rep(i,1,n){
        scanf("%s",s[i]+1);
    }
    rep(i,1,m){
        ll tt=0;
        rep(j,1,n){
            tt<<=1;
            if(s[j][i]=='1') tt|=1;
        }
        a[i]=tt;
    }
    ll ans=1;
    rep(i,1,m) if(!v[i]){
        int cnt=1;
        rep(j,i+1,m) if(a[i]==a[j]){
            ++cnt;
            v[j]=1;
        }
        ans=ans*B[cnt]%P;
    }
    printf("%d\n",(int)ans);
}