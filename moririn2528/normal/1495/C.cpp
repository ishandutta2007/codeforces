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

namespace sol{

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<string> grid(n);
        for(i=0;i<n;i++){
            cin>>grid[i];
        }
        if(n%3==0)i=1;
        else i=0;
        for(;i<n;i+=3){
            for(j=0;j<m;j++){
                grid[i][j]='X';
            }
            if(i+2>=n)break;
            for(j=0;j<m;j++){
                if(grid[i+1][j]=='X' || grid[i+2][j]=='X')break;
            }
            if(j==m)j=0;
            grid[i+1][j]='X',grid[i+2][j]='X';
        }
        for(i=0;i<n;i++){
            cout<<grid[i]<<endl;
        }
    }
}

int main(){
    int n,i;
    sol::init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}