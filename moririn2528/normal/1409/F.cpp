#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

int dp[222][222][222];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    string sa,sb;
    cin>>n>>m;
    cin>>sa>>sb;
    if(sb[0]==sb[1]){
        a=m;
        for(i=0;i<n;i++){
            if(sa[i]==sb[0])a++;
        }
        a=min(a,n);
        cout<<a*(a-1)/2<<endl;
        return 0;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            for(k=0;k<=m;k++){
                if(dp[i][j][k]==-1)continue;
                if(sa[i]==sb[0])dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]);
                else dp[i+1][j+1][k+1]=max(dp[i+1][j+1][k+1],dp[i][j][k]);
                if(sa[i]==sb[1])dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+j);
                else dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+j);
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
            }
        }
    }
    a=0;
    for(j=0;j<=n;j++){
        for(k=0;k<=m;k++){
            a=max(a,dp[n][j][k]);
        }
    }

    cout<<a<<endl;
}