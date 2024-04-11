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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=998244353;

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
    cin>>n>>m;
    vector<int> v1(n),v2;
    map<int,int> m1;
    for(i=0;i<n;i++){
        cin>>a;
        a--;
        v1[a]=i;
    }
    for(i=0;i<m;i++){
        cin>>a;
        a--;
        v2.push_back(v1[a]);
    }
    v1=v2;
    v1.push_back(-1);
    v1.push_back(n);
    sort(v1.begin(),v1.end());
    for(i=0;i+1<v1.size();i++){
        m1[v1[i]]=v1[i+1]-v1[i]-1;
    }
    LL s=1;
    for(i=0;i<m;i++){
        auto itr=m1.find(v2[i]);
        a=0;
        b=itr->second;
        if(itr->second>=1)a++;
        --itr;
        if(itr->second>=1)a++;
        s*=a;
        s%=MAX;
        itr->second+=b;
        itr++;
        m1.erase(itr);
    }
    cout<<s<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}