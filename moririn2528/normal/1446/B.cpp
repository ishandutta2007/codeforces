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

int dp[5555][5555];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    string sa,sb;
    cin>>sa>>sb;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(sa[i]==sb[j])dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+2);
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]-1);
            dp[i][j+1]=max(dp[i][j+1],dp[i][j]-1);
        }
    }
    a=0;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            a=max(a,dp[i][j]);
        }
    }
    cout<<a<<endl;
}