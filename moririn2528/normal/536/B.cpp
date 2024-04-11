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

class Zalgo{
private:
    string str;
    vector<int> pre_len;//length same to prefix
public:
    void calc_zalgo(){
        pre_len.assign(str.size(),0);
        int n=str.size();
        int i,j,k;
        pre_len[0]=str.size();
        for(i=1,j=0;i<n;){
            for(;i+j<n;j++){
                if(str[j]!=str[i+j])break;
            }
            pre_len[i]=j;
            if(j==0){
                i++;
                continue;
            }
            i++,j--;
            for(k=1;j>0 && i<n;i++,j--,k++){
                if(pre_len[k]>=j)break;
                pre_len[i]=pre_len[k];
            }
        }
    }

    void calc_zalgo(string str_temp){
        str=str_temp;
        calc_zalgo();
    }

    vector<int> get_pre_len(){
        return pre_len;
    }
};

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

using mint=modint<1'000'000'007,true>;
using modint109=modint<1'000'000'009,true>;
using modint998=modint<998'244'353,true>;

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        string sa;
        cin>>n>>m;
        cin>>sa;
        Zalgo za;
        za.calc_zalgo(sa);
        vector<int> va=za.get_pre_len(),v1;
        int s=0;
        for(i=0,b=0;i<m;i++,b=a){
            cin>>a;
            a--;
            v1.push_back(a);
            if(i==0){
                s+=a;
                continue;
            }
            if(b+(int)sa.size()<=a){
                s+=a-(b+sa.size());
                continue;
            }
            if(va[a-b]<sa.size()-(a-b)){
                cout<<0<<endl;
                return;
            }
        }
        s+=max(0,n-b-(int)sa.size());
        if(m==0)s=n;
        mint ss=26;
        cout<<ss.pow(s)<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}