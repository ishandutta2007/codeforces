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
    LL n,m;
    int i,j,k;
    LL a,b,c;
    vector<LL> v1,v2,v3;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end());
    for(i=0;i<n;i++){
        cin>>a;
    }
    v2.assign(n,0);
    for(i=0,j=0;i<n;i++){
        while(j<n && v1[j]<=v1[i]+m)j++;
        v2[i]=j-i;
    }
    v3.assign(n,0);
    a=0;
    for(i=n-1;i>=0;i--){
        a=max(a,v2[i]);
        v3[i]=a;
    }
    a=0;
    for(i=0;i<n;i++){
        b=v2[i];
        if(i+v2[i]<n)b+=v3[i+v2[i]];
        a=max(a,b);
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