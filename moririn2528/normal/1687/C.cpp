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
template<typename T1,typename T2> istream& operator>>(istream& is,pair<T1,T2>& p){
    is>>p.first>>p.second;
    return is;
}

namespace sol{

    void init(){
        
    }

    bool solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        cin>>n>>m;
        vector<LL> v1(n+1);
        vector<LL> va(n),vb(n);
        cin>>va>>vb;
        for(i=0;i<n;i++){
            v1[i+1]=v1[i]+va[i]-vb[i];
        }
        set<int> s1;
        for(i=0;i<=n;i++){
            if(v1[i])s1.insert(i);
        }
        vector<P> vp;
        vector<vector<int>> vv(n+1);
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--;
            if(v1[a]==0 && v1[b]==0){
                vp.push_back({a,b});
                continue;
            }
            if(v1[a]){
                vv[a].push_back(b);
            }
            if(v1[b]){
                vv[b].push_back(a);
            }
        }
        if(v1[n])return false;
        while(!vp.empty() && !s1.empty()){
            a=vp.back().first, b=vp.back().second;
            vp.pop_back();
            auto itr=s1.lower_bound(a);
            while(itr!=s1.end() && *itr<b){
                c=*itr;
                s1.erase(itr);
                itr=s1.lower_bound(a);
                v1[c]=0;
                for(LL to:vv[c]){
                    if(v1[to])continue;
                    int x=min(to,c),y=max(to,c);
                    vp.push_back({x,y});
                }
            }
        }
        return s1.empty();
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        if(sol::solve())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}