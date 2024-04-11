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
    ll get_mod()const{return mod;}

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
using mint=modint<998'244'353,true>;

namespace sol{

    const int N=1e6+7;
    vector<vector<P>> pri(N);

    void create_pri(){
        LL i,j,k;
        vector<int> v1(N,-1);
        for(i=2;i<N;i++){
            if(v1[i]!=-1)continue;
            for(j=i*i;j<N;j+=i){
                if(v1[j]==-1)v1[j]=i;
            }
        }
        for(i=2;i<N;i++){
            if(v1[i]==-1){
                pri[i].push_back({i,1});
                continue;
            }
            j=i/v1[i];
            pri[i]=pri[j];
            for(k=0;k<pri[i].size();k++){
                if(pri[i][k].first==v1[i]){
                    pri[i][k].second++;
                    break;
                }
            }
            if(k==pri[i].size())pri[i].push_back({v1[i],1});
        }
    }

    void solve(){
        int n,m;
        int i,j,k;
        create_pri();
        cin>>n;
        vector<mint> v1(N);
        mint a=0,b;
        for(i=1;i<=n;i++){
            v1[i]=a;
            b=1;
            for(auto node:pri[i]){
                b*=node.second+1;
            }
            v1[i]+=b;
            a+=v1[i];
        }
        cout<<v1[n]<<endl;
    }
}

int main(){
    sol::solve();
}