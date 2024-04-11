
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


template<typename T> class bit{
private:
    vector<T> bit_vec;
    int bit_N=20;

    T bit_comp(T a,T b){
        return a+b;
    }

public:

    bit(int n){
        for(bit_N=0;bit_N<30;bit_N++){
            if(n<(1<<bit_N))break;
        }
        bit_vec.assign((1<<bit_N),0);
    }

    void set(int pos,T x){
        bit_vec[pos]=bit_comp(bit_vec[pos],x);
        for(int i=0;i<bit_N;i++){
            if(pos&(1<<i))continue;
            pos|=(1<<i);
            bit_vec[pos]=bit_comp(bit_vec[pos],x);
        }
    }

    T search(int pos){
        T s=bit_vec[pos];
        for(int i=0;pos>=(1<<i);i++){
            if(pos&(1<<i))continue;
            pos-=(1<<i);
            s=bit_comp(s,bit_vec[pos]);
        }
        return s;
    }
};

namespace sol{
    typedef tuple<int,int,int> T;

    void calc(vector<T>& v1,vector<int>& vs){
        map<int,int> m1;
        int n=v1.size();
        int a,b,c;
        int i,j;
        for(i=0;i<n;i++){
            tie(ignore,a,ignore)=v1[i];
            m1[a]++;
        }
        i=0;
        for(auto& node:m1){
            node.second=i++;
        }
        bit<int> bt(v1.size());
        for(i=0;i<n;i++){
            tie(a,b,c)=v1[i];
            b=m1[b];
            if(a==1)bt.set(b,1);
            else if(a==2)bt.set(b,-1);
            else vs[c]=bt.search(b);
        }
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<int> vs(n,-1);
        map<int,int> m1;
        vector<vector<T>> v1(n);
        for(i=0;i<n;i++){
            cin>>a>>b>>c;
            if(m1.find(c)==m1.end()){
                k=m1.size();
                m1[c]=k;
            }
            c=m1[c];
            v1[c].push_back({a,b,i});
        }
        for(i=0;i<n;i++){
            if(v1[i].empty())break;
            calc(v1[i],vs);
        }
        for(i=0;i<n;i++){
            if(vs[i]!=-1)cout<<vs[i]<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}