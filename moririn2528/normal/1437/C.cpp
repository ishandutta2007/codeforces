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

void init(){
    
}

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    vector<int> v1;
    vector<vector<int>> dp(n+10,vector<int>(2*n+10,INF));
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end());
    dp[0][0]=0;
    for(i=0;i<n;i++){
        for(j=0;j<=2*n;j++){
            for(k=1;j+k<=2*n;k++){
                dp[i+1][j+k]=min(dp[i+1][j+k],dp[i][j]+abs(v1[i]-(j+k)));
            }
        }
    }
    a=INF;
    for(i=0;i<=2*n;i++){
        a=min(a,dp[n][i]);
    }
    cout<<a<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}