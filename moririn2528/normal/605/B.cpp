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

namespace sol{
    typedef tuple<int,int,int> T;

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<P> vs(m);
        vector<T> v1;
        for(i=0;i<m;i++){
            cin>>a>>b;
            v1.push_back({a,-b,i});
        }
        vector<P> v2;
        int x=1;
        sort(v1.begin(),v1.end());
        for(i=0;i<m;i++){
            tie(a,b,c)=v1[i];
            if(b==-1){
                vs[c]={0,x};
                for(j=1;j<x && v2.size()<m;j++){
                    v2.push_back({j,x});
                }
                x++;
            }else{
                if(v2.empty()){
                    cout<<-1<<endl;
                    return;
                }
                vs[c]=v2.back();
                v2.pop_back();
            }
        }
        for(auto node:vs){
            cout<<node.first+1<<" "<<node.second+1<<endl;
        }
    }
}

int main(){
    sol::solve();
}