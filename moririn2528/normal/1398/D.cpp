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

LL dp[222][222][222];

int main(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    int x,y,z;
    cin>>x>>y>>z;
    vector<LL> v1(x),v2(y),v3(z);
    for(i=0;i<x;i++){
        cin>>v1[i];
    }
    for(i=0;i<y;i++){
        cin>>v2[i];
    }
    for(i=0;i<z;i++){
        cin>>v3[i];
    }
    sort(v1.rbegin(),v1.rend());
    sort(v2.rbegin(),v2.rend());
    sort(v3.rbegin(),v3.rend());
    for(i=0;i<=x;i++){
        for(j=0;j<=y;j++){
            for(k=0;k<=z;k++){
                if(i<x && j<y)dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+v1[i]*v2[j]);
                if(i<x && k<z)dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+v1[i]*v3[k]);
                if(j<y && k<z)dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]+v2[j]*v3[k]);
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
                dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
                dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]);
            }
        }
    }
    cout<<dp[x][y][z]<<endl;
}