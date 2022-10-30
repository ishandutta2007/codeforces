#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int K,T;

int C[10][10];
signed main(){
    rep(i,10){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    cin>>K>>T;
    int cnt[16];
    for(int i=0;i<(1<<20);i++){
        memset(cnt,0,sizeof(cnt));
        bool ex=false;
        for(int j=4;j>=0;j--){
            int t=i>>(4*j)&15;
            if(ex||t)cnt[t]++;
            if(t)ex=true;
        }
        bool ok=true;
        rep(j,16)if(cnt[j]>T)ok=false;
        if(ok){
            if(K==0){
                printf("%llx\n",i);
                return 0;
            }
            K--;
        }
    }
    int dp[20][6];
    int tar;
    for(int i=1;i<(1<<16);i++){
        memset(cnt,0,sizeof(cnt));
        bool ex=false;
        for(int j=3;j>=0;j--){
            int t=i>>(4*j)&15;
            if(ex||t)cnt[t]++;
            if(t)ex=true;
        }
        bool ok=true;
        rep(j,16)if(cnt[j]>T)ok=false;
        if(!ok)continue;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int j=0;j<16;j++){
            for(int k=0;k<=5;k++){
                for(int l=0;k+l<=5&&cnt[j]+l<=T;l++){
                    dp[j+1][k+l]+=dp[j][k]*C[5-k][l];
                }
            }
        }
        if(K<dp[16][5]){
            tar=i;
            break;
        }
        K-=dp[16][5];
    }

    for(int i=0;i<(1<<20);i++){
        int d=(tar<<20)+i;
        memset(cnt,0,sizeof(cnt));
        bool ex=false;
        for(int j=8;j>=0;j--){
            int t=d>>(4*j)&15;
            if(ex||t)cnt[t]++;
            if(t)ex=true;
        }
        bool ok=true;
        rep(j,16)if(cnt[j]>T)ok=false;
        if(ok){
            if(K==0){
                printf("%llx\n",d);
                return 0;
            }
            K--;
        }
    }

    return 0;
}