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

long long int gcd(long long int a,long long int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

namespace sol{
    void modify(map<LL,LL>& m1){
        LL a=0;
        for(auto node:m1){
            a=gcd(a,node.second);
        }
        assert(a!=0);
        for(auto& node:m1){
            node.second/=a;
        }
    }

    void solve(){
        LL n,m;
        int i,j,k;
        LL a,b,c;
        map<LL,LL> mx,my;
        map<LP,LL> mp;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a>>b>>c;
            mx[a]+=c,my[b]+=c;
            mp[{a,b}]+=c;
        }
        if(mx.size()*my.size()>n){
            cout<<0<<endl;
            return;
        }
        modify(mx),modify(my);
        a=-1;
        for(auto na:mx){
            for(auto nb:my){
                b=mp[{na.first,nb.first}],c=na.second*nb.second;
                if(b%c){
                    cout<<0<<endl;
                    return;
                }
                b/=c;
                if(a!=-1 && a!=b){
                    cout<<0<<endl;
                    return;
                }
                a=b;
            }
        }
        LL s=0;
        for(b=1;b<=1e6;b++){
            if(a%b)continue;
            if(a/b<b)continue;
            s++;
            if(a!=b*b)s++;
        }
        cout<<s<<endl;
    }
}

int main(){
    sol::solve();
}