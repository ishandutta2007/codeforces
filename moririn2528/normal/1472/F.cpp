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

void init(){
    
}

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n>>m;
    vector<P> v1;
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        v1.push_back(make_pair(b,a));
    }
    sort(v1.begin(),v1.end());
    map<int,int> m1;
    b=-1;
    for(i=0;i<m;i++){
        a=v1[i].first;
        if(m1.find(a)!=m1.end())continue;
        b++;
        if(a%2!=b%2)b++;
        m1[a]=b;
    }
    b++;
    if(n%2!=b%2)b++;
    n=b;
    vector<vector<char>> dp(n+10,vector<char>(3));
    vector<vector<char>> bl(n+2,vector<char>(2));
    for(i=0;i<m;i++){
        a=v1[i].first,b=v1[i].second;
        bl[m1[a]][b]=1;
    }
    dp[0][0]=1;
    for(i=0;i<n;i++){
        if(dp[i][0]){
            if(!bl[i][0] && !bl[i][1])dp[i+1][0]=1;
            else if(bl[i][0] && bl[i][1])dp[i+1][0]=1;
            else if(bl[i][0])dp[i+1][2]=1;
            else dp[i+1][1]=1;
        }
        if(dp[i][1] && !bl[i][0]){
            if(bl[i][1])dp[i+1][0]=1;
            else dp[i+1][2]=1;
        }
        if(dp[i][2] && !bl[i][1]){
            if(bl[i][0])dp[i+1][0]=1;
            else dp[i+1][1]=1;
        }
    }
    if(dp[n][0])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}