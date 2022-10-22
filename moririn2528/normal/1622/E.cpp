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

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<int> v1(n);
        vector<vector<char>> va(m,vector<char>(n));
        cin>>v1;
        string sa;
        for(i=0;i<n;i++){
            cin>>sa;
            for(j=0;j<m;j++){
                va[j][i]=sa[j]-'0';
            }
        }
        vector<int> vs;
        int s=-1;
        for(i=0;i<(1<<n);i++){
            vector<P> vp;
            for(j=0;j<m;j++){
                a=0;
                for(k=0;k<n;k++){
                    if(va[j][k]){
                        if(i&1<<k)a++;
                        else a--;
                    }
                }
                vp.push_back({a,j});
            }
            sort(vp.begin(),vp.end());
            vector<int> vt(m);
            for(j=0;j<m;j++){
                a=vp[j].second;
                vt[a]=j+1;
            }
            vector<int> v(n);
            for(j=0;j<m;j++){
                for(k=0;k<n;k++){
                    if(va[j][k])v[k]+=vt[j];
                }
            }
            a=0;
            for(j=0;j<n;j++){
                a+=abs(v[j]-v1[j]);
            }
            if(s<a){
                s=a;
                vs=vt;
            }
        }
        cout<<vs<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}