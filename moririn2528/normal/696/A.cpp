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

    map<LL,LL> cost;
    
    void increase(LL a,LL b,LL c){
        while(a>b){
            cost[a]+=c;
            a/=2;
        }
        assert(a==b);
    }
    LL calc(LL a,LL b){
        LL s=0;
        while(a>b){
            s+=cost[a];
            a/=2;
        }
        assert(a==b);
        return s;
    }

    LL lca(LL a,LL b){
        set<LL> s1;
        while(a>0){
            s1.insert(a);
            a/=2;
        }
        while(b>0){
            if(s1.find(b)!=s1.end())return b;
            b/=2;
        }
        assert(false);
        return 0;
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c,d;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a;
            if(a==1){
                cin>>a>>b>>c;
                d=lca(a,b);
                increase(a,d,c);
                increase(b,d,c);
            }else{
                cin>>a>>b;
                d=lca(a,b);
                cout<<calc(a,d)+calc(b,d)<<endl;
            }
        }
    }
}

int main(){
    sol::solve();
}