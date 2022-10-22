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
const LL INF=1LL<<60;
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

LL dp[1100000][2];

int main(){
    int n,m;
    LL r1,r2,r3,d;
    int i,j,k;
    LL a,b,c;
    vector<LL> v1;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>r1>>r2>>r3>>d;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    dp[0][0]=-d,dp[0][1]=-2*d;
    for(i=0;i<n;i++){
        dp[i+1][0]=dp[i][0]+v1[i]*r1+r3+d;
        dp[i+1][0]=min(dp[i+1][0],INF);
        a=min(r2,(v1[i]+1)*r1)+r1;
        if(i<n-1)dp[i+1][1]=min(dp[i][0]+a+d,dp[i][1]+a+2*d);
        else dp[i+1][1]=min(dp[i][1]+a+4*d,dp[i][1]+v1[i]*r1+r3+2*d);
        if(i){
            a=dp[i-1][0]+min(r2,(v1[i-1]+1)*r1)+min(r2,(v1[i]+1)*r1)+d*4+r1*2;
            dp[i+1][0]=min(dp[i+1][0],a);
        }
        dp[i+1][0]=min(dp[i+1][0],dp[i][0]+min(r2,(v1[i]+1)*r1)+3*d+r1);
    }


    // cout<<endl;
    // for(i=0;i<=n;i++){
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    // }
    // cout<<endl;

    
    a=min(dp[n][0],dp[n][1]);
    cout<<a<<endl;
}