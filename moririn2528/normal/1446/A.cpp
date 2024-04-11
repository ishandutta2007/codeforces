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
    LL n,m;
    int i,j,k;
    LL a,b,c;
    vector<pair<LL,int>> v1;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(make_pair(a,i+1));
    }
    sort(v1.rbegin(),v1.rend());
    vector<int> vs;
    a=0;
    for(i=0;i<n;i++){
        if(m-a>=v1[i].first)a+=v1[i].first,vs.push_back(v1[i].second);
    }
    sort(vs.begin(),vs.end());
    if((m+1)/2<=a){
        cout<<vs.size()<<endl;
        array_show(vs);
    }else cout<<-1<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}