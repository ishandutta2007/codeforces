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

void init(){
    
}

void solve(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n;
    vector<int> v1(n);
    vector<vector<int>> cnt(n+10,vector<int>(n+10));
    for(i=0;i<n;i++){
        cin>>v1[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(v1[i]==v1[j])cnt[i+1][j+1]++;
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i)cnt[i][j]+=cnt[i-1][j];
            if(j)cnt[i][j]+=cnt[i][j-1];
            if(i && j)cnt[i][j]-=cnt[i-1][j-1];
        }
    }
    a=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(v1[i]!=v1[j])continue;
            a+=cnt[j][n]-cnt[j][j+1]-cnt[i+1][n]+cnt[i+1][j+1];
        }
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