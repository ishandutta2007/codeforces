#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=1000000007;
void plusle(int &a,int b){
    a+=b;if(a>=mod)a-=mod; return;
}
void minun(int &a,int b){
    a-=b; if(a<0)a+=mod; return;
}
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}
int c[52][52][52][4];
//number of ways to rearrange x y z of type 1 2 3 and end at each one
int n,t,f[51],ct[3],d[3];
int dp[51][2501];// the number of ways to choose subset of size i with total sum==j
int dp2[51][51][2501];//the number of ways to choose i of 1 j of 2 to get sum==5=k

int main(){        
        scanf("%d%d",&n,&t);
        c[0][0][0][3]=1;
        f[0]=1;
        for(int i=1;i<=50;i++)f[i]=mul(f[i-1],i);
        dp[0][0]=1;
        dp2[0][0][0]=1;
        int x,y;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);y--;
            if(y==0){
                for(int j=ct[0];j>=0;j--){
                    for(int k=0;k<=d[0];k++){
                        plusle(dp[j+1][k+x],dp[j][k]);
                    }
                }
            }
            else{
                for(int j=ct[1];j>=0;j--)
                for(int k=ct[2];k>=0;k--){
                    for(int l=0;l<=d[1]+d[2];l++){
                        plusle(dp2[j+(y==1)][k+(y==2)][l+x],dp2[j][k][l]);
                }
            }
            }
            d[y]+=x;++ct[y];
        }
        for(int i=0;i<=ct[0];i++){
            for(int j=0;j<=ct[1];j++){
                for(int k=0;k<=ct[2];k++){
            for(int last=0;last<=3;last++){
                if(c[i][j][k][last]>0){
                    for(int nt=0;nt<3;nt++){
                        if(nt!=last)
                        plusle(c[i+(nt==0?1:0)][j+(nt==1?1:0)][k+(nt==2?1:0)][nt],c[i][j][k][last]);
                    }
                }
            }
        }
        }
        }
        int ans=0;
    for(int i=0;i<=ct[0];i++)
        for(int j=0;j<=d[0];j++){
            if(t>=j){
                for(int k=0;k<=ct[1];k++)
                for(int l=0;l<=ct[2];l++){
                  x=mul(dp[i][j],dp2[k][l][t-j]);
                  x=mul(x,mul(f[i],mul(f[k],f[l])));
                  for(int m=0;m<3;m++){
                        plusle(ans,mul(x,c[i][k][l][m]));
                  }
                }
            }
        }
        printf("%d\n",ans);

}
/*
    Good Luck
         -Lucina
*/