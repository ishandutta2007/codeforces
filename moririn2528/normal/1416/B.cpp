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
    LL s=0;
    cin>>n;
    vector<int> v1;
    vector<tuple<int,int,int>> vs;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
        s+=a;
    }
    if(s%n){
        cout<<-1<<endl;
        return;
    }
    for(i=1;i<n;i++){
        a=(v1[i]-1)/(i+1)+1;
        b=a*(i+1)-v1[i];
        vs.push_back(make_tuple(1,i+1,b));
        vs.push_back(make_tuple(i+1,1,a));
    }
    s/=n;
    for(i=1;i<n;i++){
        vs.push_back(make_tuple(1,i+1,s));
    }
    cout<<vs.size()<<endl;
    for(auto node:vs){
        tie(a,b,c)=node;
        cout<<a<<" "<<b<<" "<<c<<endl;
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