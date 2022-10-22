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

void flip(int x,int y,vector<string>& grid){
    assert(grid[x][y]!='.');
    if(grid[x][y]=='O')grid[x][y]='X';
    else grid[x][y]='O';
}

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    vector<string> grid(n);
    vector<P> vx,vy;
    int x=-1,y=-1;
    for(i=0;i<n;i++){
        cin>>grid[i];
    }
    vector<int> cnt(3);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(grid[i][j]=='.')continue;
            cnt[(i+j)%3]++;
        }
    }
    a=0;
    for(k=0;k<3;k++){
        if(cnt[a]>cnt[k])a=k;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if((i+j+3-a)%3)continue;
            if(grid[i][j]=='.')continue;
            grid[i][j]='O';
        }
    }
    for(i=0;i<n;i++){
        cout<<grid[i]<<endl;
    }
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}