#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=500;

int N;
int c[SIZE];

int dp[SIZE][SIZE];

signed main(){
    scanf("%d",&N);
    rep(i,N)scanf("%d",&c[i]);

    fill_n(*dp,SIZE*SIZE,1001001001);
    for(int len=1;len<=N;len++){
        for(int i=0;i+len<=N;i++){
            int j=i+len-1;
            for(int k=i;k<=j;k++){
                if(c[k]!=c[i])continue;
                int tmp=0;
                if(k!=j)tmp+=dp[k+1][j];
                if(i+1<=k-1)tmp+=dp[i+1][k-1]-1;
                dp[i][j]=min(dp[i][j],tmp+1);
            }
        }
    }

    printf("%d\n",dp[0][N-1]);
    return 0;
}