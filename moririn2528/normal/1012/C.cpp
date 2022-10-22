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

int dp[5500][3000][3];
int t[5500];

void dp_set(int &a, int b){
    if(a==-1)a=b;
    else if(a>b)a=b;
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        t[i+1]=a;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][2]=0;
    for(i=0;i<n;i++){
        for(j=0;j<=(n+1)/2;j++){
            for(k=0;k<3;k++){
                if(dp[i][j][k]==-1)continue;
                if(k<=1)dp_set(dp[i+1][j][k+1],dp[i][j][k]);
                else dp_set(dp[i+1][j][k],dp[i][j][k]);
                if(k==2){
                    dp_set(dp[i+1][j+1][0],dp[i][j][k]+max(t[i]-t[i+1]+1,0)+max(t[i+2]-t[i+1]+1,0));
                }
                if(k==1){
                    a=dp[i][j][k]+max(t[i+2]-t[i+1]+1,0);
                    a+=max(min(t[i-1]-1,t[i])-t[i+1]+1,0);
                    dp_set(dp[i+1][j+1][0],a);
                }
            }
        }
    }
    vector<int> v1;
    for(i=1;i<=(n+1)/2;i++){
        a=INF;
        for(j=0;j<3;j++){
            if(dp[n][i][j]!=-1)a=min(a,dp[n][i][j]);
        }
        v1.push_back(a);
    }
    array_show(v1);
}