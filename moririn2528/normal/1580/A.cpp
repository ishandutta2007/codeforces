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
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,LL> LP;
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
template<typename T> ostream& operator<<(ostream& os,const vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++){
        if(i)os<<" ";
        os<<v1[i];
    }
    return os;
}
template<typename T1,typename T2> ostream& operator<<(ostream& os,const pair<T1,T2>& p){
    os<<p.first<<" "<<p.second;
    return os;
}
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}
template<typename T1,typename T2> istream& operator>>(istream& is,pair<T1,T2>& p){
    is>>p.first>>p.second;
    return is;
}

namespace sol{

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k,l;
        int a,b,c;
        cin>>n>>m;
        vector<string> v1(n);
        vector<vector<int>> grid(n+1,vector<int>(m+1,0));
        vector<vector<int>> grids(n+1,vector<int>(m+1,0));
        cin>>v1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                a=v1[i][j]-'0';
                grids[i+1][j]=grids[i][j]+a;
                grid[i][j]=a;
            }
        }
        int s=INF;
        for(i=0;i<n;i++){
            for(j=i+4;j<n;j++){
                vector<int> dp(m+10,INF);
                for(k=0;k<m;k++){
                    a=b=j-i-1-(grids[j][k]-grids[i+1][k]);
                    if(k<m-3){
                        for(l=k+1;l<=k+2;l++){
                            a+=2-grid[i][l]-grid[j][l];
                            a+=grids[j][l]-grids[i+1][l];
                        }
                        dp[k+3]=a;
                    }
                    s=min(s,dp[k]+b);
                    dp[k+1]=min(dp[k+1],dp[k]+2-grid[i][k]-grid[j][k]+grids[j][k]-grids[i+1][k]);
                }
            }
        }
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}