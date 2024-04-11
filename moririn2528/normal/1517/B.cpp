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

namespace sol{

    typedef tuple<int,int,int> T;

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<vector<int>> v1(n,vector<int>(m));
        vector<vector<int>> v2(n,vector<int>(m));
        priority_queue<T,vector<T>,greater<T>> q1;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>v1[i][j];
                q1.push({v1[i][j],i,j});
            }
        }
        for(i=0;i<m;i++){
            tie(a,b,c)=q1.top();q1.pop();
            v2[b][i]=a;
        }
        vector<int> vi(n);
        while(!q1.empty()){
            tie(a,b,c)=q1.top();q1.pop();
            for(j=vi[b];j<m && v2[b][j];j++);
            vi[b]=j;
            v2[b][j]=a;
        }
        for(i=0;i<n;i++){
            cout<<v2[i]<<endl;
        }
    }
}


int main(){
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}