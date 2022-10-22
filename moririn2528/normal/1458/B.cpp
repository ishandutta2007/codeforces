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
#include<complex>
#include<numeric>
#include<functional>
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

int dp[111][11111];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    int wat=0;
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(i=0;i<n;i++){
        cin>>a>>b;
        wat+=b;
        for(j=n;j>=0;j--){
            for(k=1e4;k>=0;k--){
                if(dp[j][k]==-1)continue;
                dp[j+1][k+a]=max(dp[j+1][k+a],dp[j][k]+b);
            }
        }
    }
    double db,dc;
    for(i=0;i<n;i++){
        double da=0;    
        for(j=0;j<=1e4;j++){
            if(dp[i+1][j]==-1)continue;
            db=j-dp[i+1][j],dc=wat-dp[i+1][j];
            da=max(da,dp[i+1][j]+min(db,dc/2));
        }
        if(i)cout<<" ";
        cout<<da;
    }
    cout<<endl;
}