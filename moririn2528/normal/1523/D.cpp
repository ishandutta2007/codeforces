#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

    void solve(){
        int n,m,p,q;
        int i,j,k;
        LL a,b,c;
        string sa;
        cin>>n>>m>>p;
        vector<LL> v1(n),v2;
        unordered_map<LL,int> m1;
        for(i=0;i<n;i++){
            cin>>sa;
            a=0;
            for(j=0;j<m;j++){
                a*=2;
                a+=sa[j]-'0';
            }
            v1[i]=a;
        }
        for(i=0;i<m;i++){
            a=0;
            for(j=0;j<n;j++){
                if(v1[j]&1LL<<i)a++;
            }
            if(a>=(n+1)/2)v2.push_back(i);
        }
        for(i=0;i<n;i++){
            a=0;
            for(j=0;j<v2.size();j++){
                if(v1[i]&1LL<<v2[j])a+=1LL<<j;
            }
            v1[i]=a;
            m1[a]++;
        }
        q=v2.size();
        vector<LP> va;
        for(j=0;j<q;j++){
            va.clear();
            for(auto& itr:m1){
                a=itr.first;
                if(~a&1LL<<j)continue;
                va.push_back({a-(1LL<<j),itr.second});
            }
            for(auto& node:va){
                m1[node.first]+=node.second;
            }
        }
        a=0,b=0;
        for(auto& itr:m1){
            if(itr.second<(n+1)/2)continue;
            c=__builtin_popcountll(itr.first);
            if(a<c)a=c,b=itr.first;
        }
        string ss(m,'0');
        for(i=0;i<q;i++){
            if(b&1LL<<i)ss[m-1-v2[i]]='1';
        }
        cout<<ss<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}