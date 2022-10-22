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

template<typename type> class Matrix{
public:
    vector<vector<type>> vec_matrix;
private:
    void init(int n){
        vec_matrix.assign(n,vector<type>(n,0));
    }
public:
    Matrix(int n){
        init(n);
    }
    Matrix(vector<vector<type>> ma):vec_matrix(ma){};

    bool valid() const{
        int n=size();
        assert(n>0 && (int)vec_matrix[0].size()==n);
        if(n>0 && (int)vec_matrix[0].size()==n)return true;
        else return false;
    }

    void E(){
        valid();
        for(int i=0;i<size();i++){
            vec_matrix[i][i]=1;
        }
    }
    void E(int n){
        init(n);
        E();
    }

    int size() const{
        return vec_matrix.size();
    }

    Matrix& operator += (const Matrix& matrix_a){
        const vector<vector<type>>& vec_matrix_a=matrix_a.vec_matrix;
        valid(),matrix_a.valid();
        int i,j;
        int n=size();
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                vec_matrix[i][j]+=vec_matrix_a[i][j];
            }
        }
        return *this;
    }

    Matrix& operator *= (const Matrix& matrix_a){
        const vector<vector<type>>& vec_matrix_a=matrix_a.vec_matrix;
        valid(),matrix_a.valid();
        int i,j,k;
        int n=size();
        vector<vector<type>> vec_matrix_b(n,vector<type>(n,0));
        for(i=0;i<n;i++){
            for(k=0;k<n;k++){
                for(j=0;j<n;j++){
                    vec_matrix_b[i][j]+=vec_matrix[i][k]*vec_matrix_a[k][j];					
                }
            }
        }
        vec_matrix=vec_matrix_b;
        return *this;
    }

    Matrix operator +(const Matrix& matrix_a){
        Matrix matrix_s=*this;
        matrix_s+=matrix_a;
        return matrix_s;
    }

    Matrix operator *(const Matrix& matrix_a){
        Matrix matrix_s=*this;
        matrix_s*=matrix_a;
        return matrix_s;
    }

    Matrix pow(Matrix& ma,long long int m){
        long long int p_b=1;
        Matrix<type> ms(ma.size());
        ms.E();
        for(;p_b<=m;p_b<<=1);
        for(p_b>>=1;p_b>0;p_b>>=1){
            ms*=ms;
            if(m&p_b)ms*=ma;
        }
        return ms;
    }
    Matrix& pow(long long int m){
        (*this)=pow((*this),m);
        return *this;
    }

    type get_matrix_element(int a,int b) const{
        assert(a<size() && b<size());
        return vec_matrix[a][b];
    }
};


namespace sol{

    void solve(){
        int n,m,p;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        string sa,sb;
        vector<string> v1;
        set<string> s1,s2;
        map<pair<string,int>,int> m1;
        vector<pair<string,int>> vp;
        s1.insert("");
        for(i=0;i<n;i++){
            cin>>sa;
            v1.push_back(sa);
            s2.insert(sa);
            while(!sa.empty()){
                s1.insert(sa);
                sa.pop_back();
            }
        }
        for(auto& str:s1){
            sa=str;
            m1[{str,0}]=vp.size();
            vp.push_back({str,0});
            for(i=1;i<=str.size();i++){
                sa.erase(sa.begin());
                if(s1.find(sa)==s1.end())continue;
                m1[{str,i}]=vp.size();
                vp.push_back({str,i});
            }
        }
        p=vp.size();
        vector<vector<mint>> vm(p,vector<mint>(p));
        for(i=0;i<p;i++){
            sa=vp[i].first,a=vp[i].second;
            for(char ca='a';ca<='z';ca++){
                sa.push_back(ca);
                sb=sa.substr(a);
                if(s2.find(sa)!=s2.end() && s2.find(sb)!=s2.end())vm[i][m1[{"",0}]]++;
                if(s2.find(sa)!=s2.end() && s1.find(sb)!=s1.end())vm[i][m1[{sb,sb.size()}]]++;
                if(s2.find(sb)!=s2.end() && s1.find(sa)!=s1.end())vm[i][m1[{sa,sa.size()}]]++;
                if(m1.find({sa,a})!=m1.end())vm[i][m1[{sa,a}]]++;
                sa.pop_back();
            }
        }
        Matrix<mint> ma(vm);
        int id=m1[{"",0}];
        ma.pow(m);
        cout<<ma.get_matrix_element(id,id)<<endl;
    }
}

int main(){
    sol::solve();
}