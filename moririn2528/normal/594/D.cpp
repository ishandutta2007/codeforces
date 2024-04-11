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

template<typename T>T ext_gcd(T a,T b,T& x,T& y){
    //ax+by=gcd(a,b)
    if(a<b)return ext_gcd(b,a,y,x);
    if(b==0){
        x=1,y=0;
        return a;
    }
    T gcd_val=ext_gcd(b,a%b,x,y);
    swap(x,y);
    y-=x*(a/b);
    if(x>b)y+=(x/b)*a,x%=b;
    if(y>a)x+=(y/a)*b,y%=a;
    return gcd_val;
}

template<long long int mod,bool prime=false>class modint{
private:
    typedef long long int ll;
    ll val;

    ll gcd(ll a,ll b){
        if(a<b)swap(a,b);
        if(b==0)return a;
        return gcd(b,a%b);
    }
public:
    modint():val(0){}
    template<class T>modint(T a){
        val=(ll)a%mod;
        if(val<0)val+=mod;
    }

    ll value()const{return val;}

    modint& operator++(){
        val++;
        if(val==mod)val=0;
        return *this;
    }
    modint operator++(int){
        modint ans=*this;
        ++*this;
        return ans;
    }
    modint& operator--(){
        if(val==0)val=mod;
        val--;
        return *this;
    }
    modint operator--(int){
        modint ans=*this;
        --*this;
        return ans;
    }

    modint& operator+=(const modint& a){
        val+=a.value();
        if(val>=mod)val-=mod;
        return *this;
    }
    modint& operator-=(const modint& a){
        val-=a.value();
        if(val<0)val+=mod;
        return *this;
    }
    modint& operator*=(const modint& a){
        val*=a.value();
        if(val>=mod)val%=mod;
        return *this;
    }

    modint pow(ll index)const{
        assert(index>=0);
        if(prime && index>=mod-1)index%=mod-1;
        modint a=*this,ans=1;
        for(ll i=1;i>=0 && i<=index;i<<=1){
            if(index&i)ans*=a;
            a*=a;
        }
        return ans;
    }

    modint inverse()const{
        if(prime){
            assert(val!=0);
            return pow(mod-2);
        }
        ll x,y;
        ll g=ext_gcd<ll>(val,mod,x,y);
        assert(g==1);
        return x;
    }

    modint& operator/=(const modint& a){
        if(prime){
            *this=(*this)*a.inverse();
            return *this;
        }
        ll g=gcd(val,a.value());
        modint a2=a.value()/g;
        val/=g;
        *this=(*this)*a2.inverse();
        return *this;
    }

    friend modint operator-(const modint& a,const modint& b){return (modint)a-=b;}
    friend modint operator+(const modint& a,const modint& b){return (modint)a+=b;}
    friend modint operator*(const modint& a,const modint& b){return (modint)a*=b;}
    friend modint operator/(const modint& a,const modint& b){return (modint)a/=b;}
    friend bool operator==(const modint& a,const modint& b){return a.value()==b.value();}
    friend bool operator!=(const modint& a,const modint& b){return a.value()!=b.value();}
    
    friend modint pow(const modint& a,const ll b){return a.pow(b);}

    modint operator+() const{return *this;}
    modint operator-() const{return modint()-*this;}

    friend ostream& operator<<(ostream& os,const modint& a){
        os<<a.value();
        return os;
    }
    friend istream& operator>>(istream& is,modint& a){
        ll val;
        is>>val;
        a=val;
        return is;
    }
};

using modint107=modint<1'000'000'007,true>;
using modint109=modint<1'000'000'009,true>;
using modint998=modint<998'244'353,true>;

template<typename T> class bit{
private:
    vector<T> bit_vec;
    int bit_N=20;

    T bit_comp(T a,T b){
        return a*b;
    }

public:

    bit(int n){
        for(bit_N=0;bit_N<30;bit_N++){
            if(n<(1<<bit_N))break;
        }
        bit_vec.assign((1<<bit_N),1);
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

using mint=modint107;

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        mint ma,mb;
        const int M=1e6+7;
        cin>>n;
        vector<int> v1(n);
        vector<vector<int>> vp(n),v2(M);
        for(i=0;i<n;i++){
            cin>>a;
            v1[i]=a;
            for(j=2;j<1e3;j++){
                for(k=0;a%j==0;k++,a/=j);
                if(k){
                    vp[i].push_back(j);
                    v2[j].push_back(i);
                }
            }
            if(a>1){
                vp[i].push_back(a);
                v2[a].push_back(i);
            }
        }
        for(i=0;i<M;i++){
            if(!v2[i].empty())sort(v2[i].rbegin(),v2[i].rend());
        }
        cin>>m;
        vector<mint> vs(m);
        vector<vector<P>> vq(n);
        bit<mint> bt(n);
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            vq[a].push_back({b,i});
        }
        for(i=0;i<n;i++){
            ma=v1[i];
            for(auto p:vp[i]){
                if(v2[p].back()==i){
                    ma*=p-1;
                    ma/=p;
                }
            }
            bt.set(i,ma);
        }
        for(i=0;i<n;i++){
            for(auto query:vq[i]){
                vs[query.second]=bt.search(query.first);
            }
            ma=bt.search(i);
            bt.set(i,1/ma);
            for(auto p:vp[i]){
                v2[p].pop_back();
                if(v2[p].empty())continue;
                j=v2[p].back();
                ma=p-1;
                bt.set(j,ma/p);
            }
        }
        for(i=0;i<m;i++){
            cout<<vs[i]<<endl;
        }
    }
}

int main(){
    sol::solve();
}