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
    int a,b,c;
    map<int,int> m1,m2;
    vector<int> v1,vs;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        m1[a]=-1,m2[a]=0;
        v1.push_back(a);
    }
    for(i=0;i<n;i++){
        a=v1[i];
        m2[a]=max(m2[a],i-m1[a]);
        m1[a]=i;
    }
    vs.assign(n,INF);
    for(auto node:m1){
        a=node.first;
        b=max(m2[a],n-m1[a]);
        vs[b-1]=min(vs[b-1],a);
    }
    for(i=0;i<n-1;i++){
        vs[i+1]=min(vs[i+1],vs[i]);
    }
    for(i=0;i<n;i++){
        if(vs[i]==INF)vs[i]=-1;
    }
    array_show(vs);
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}