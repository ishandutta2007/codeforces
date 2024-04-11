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

template<typename T> class Matrix{
private:
    typedef long long int ll;

    T zero=0,e=1;
    vector<vector<T>> vec_matrix;
    void init(int n,int m);
    function<bool(T,T)> same=[](T a,T b){return a==b;};
    //function<bool(T,T)> same=[](T a,T b){return (a-b)<=1e-9;};

    Matrix gauss_and_inverse(int mode)const;
public:
    Matrix(int n);
    Matrix(int n,int m);
    Matrix(vector<vector<T>>& ma);

    int sizeX() const;
    int sizeY() const;
    bool valid() const;

    T& element(int a,int b);
    const vector<vector<T>>& get_vec()const;
    void set_same_function(function<bool(T,T)> _same){same=_same;}

    void E();
    void E(int n);
    Matrix& operator += (const Matrix& mat_a);
    Matrix& operator -= (const Matrix& mat_a);
    Matrix& operator *= (const Matrix& mat_a);
    friend Matrix operator +(const Matrix& mat_a,const Matrix& mat_b){return (Matrix)mat_a+=mat_b;}
    friend Matrix operator -(const Matrix& mat_a,const Matrix& mat_b){return (Matrix)mat_a-=mat_b;}
    friend Matrix operator *(const Matrix& mat_a,const Matrix& mat_b){return (Matrix)mat_a*=mat_b;}
    
    Matrix operator+() const{return *this;}
    Matrix operator-() const{return Matrix()-*this;}

    Matrix& operator %= (const T mod);

    Matrix pow_mod(ll m,ll mod=1e9+7)const;
    Matrix pow(ll m)const;

    T tr()const;
    Matrix gauss()const;
    T det()const;
    Matrix inverse()const;
    Matrix submatrix(int a,int b,int c,int d)const;//[a,c)*[b,d)
};

template<typename T> void Matrix<T>::init(int n,int m){
    vec_matrix.assign(n,vector<T>(m,zero));
}
template<typename T> bool Matrix<T>::valid() const{
    int n=sizeX(),m=sizeY();
    for(int i=0;i<n;i++){
        if((int)vec_matrix[i].size()!=m)return false;
    }
    return true;
}

template<typename T> Matrix<T>::Matrix(int n){
    init(n,n);
}
template<typename T> Matrix<T>::Matrix(int n,int m){
    init(n,m);
}
template<typename T> Matrix<T>::Matrix(vector<vector<T>>& ma):vec_matrix(ma){
    assert(valid());
};

template<typename T> int Matrix<T>::sizeX() const{
    return vec_matrix.size();
}
template<typename T> int Matrix<T>::sizeY() const{
    if(vec_matrix.empty())return 0;
    return vec_matrix[0].size();
}

template<typename T> void Matrix<T>::E(){
    assert(sizeX()==sizeY());
    int n=sizeX();
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            vec_matrix[i][j]=(i==j)?e:zero;
        }
    }
}
template<typename T> void Matrix<T>::E(int n){
    init(n,n);
    E();
}

template<typename T> Matrix<T>& Matrix<T>::operator += (const Matrix<T>& mat){
    const vector<vector<T>>& vec_mat=mat.get_vec;
    assert(sizeX()==mat.sizeX() && sizeY()==mat.sizeY());
    int i,j;
    int n=sizeX(),m=sizeY();
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            vec_matrix[i][j]+=vec_mat[i][j];
        }
    }
    return *this;
}

template<typename T> Matrix<T>& Matrix<T>::operator -= (const Matrix<T>& mat){
    const vector<vector<T>>& vec_mat=mat.get_vec;
    assert(sizeX()==mat.sizeX() && sizeY()==mat.sizeY());
    int i,j;
    int n=sizeX(),m=sizeY();
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            vec_matrix[i][j]-=vec_mat[i][j];
        }
    }
    return *this;
}

template<typename T> Matrix<T>& Matrix<T>::operator *= (const Matrix<T>& mat){
    const vector<vector<T>>& vec_mat=mat.get_vec();
    assert(mat.sizeX()==sizeY());
    int i,j,k;
    int n=sizeX(),m=mat.sizeY(),p=sizeY();
    vector<vector<T>> vec_mats(n,vector<T>(m,zero));
    for(i=0;i<n;i++){
        for(k=0;k<p;k++){
            for(j=0;j<m;j++){
                vec_mats[i][j]+=vec_matrix[i][k]*vec_mat[k][j];
            }
        }
    }
    vec_matrix=vec_mats;
    return *this;
}

template<typename T> Matrix<T>& Matrix<T>::operator %= (const T mod){
    for(auto& vm:vec_matrix){
        for(auto& num:vm){
            if(num>=mod)num%=mod;
        }
    }
    return *this;
}

template<typename T> vector<T> operator *(const Matrix<T>& mat,const vector<T>& v1){
    const vector<vector<T>>& vec_mat=mat.get_vec();
    assert(!vec_mat.empty() && vec_mat[0].size()==v1.size());
    int n=vec_mat.size(),m=vec_mat[0].size();
    vector<T> vs(n);
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            vs[i]+=vec_mat[i][j]*v1[j];
        }
    }
    return vs;
}

template<typename T> istream& operator >> (istream& is,Matrix<T>& a){
    assert(a.valid());
    int n=a.sizeX(),m=a.sizeY();
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            is>>a.element(i,j);
        }
    }
    return is;
}

template<typename T> ostream& operator << (ostream& os,Matrix<T>& a){
    assert(a.valid());
    int n=a.sizeX(),m=a.sizeY();
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(j)cout<<" ";
            os<<a.element(i,j);
        }
        os<<endl;
    }
    return os;
}

template<typename T> Matrix<T> Matrix<T>::pow_mod(ll m,ll mod)const{
    assert(sizeX()==sizeY());
    ll p_b=1;
    Matrix<T> ms(sizeX());
    ms.E();
    for(;p_b<=m;p_b<<=1);
    for(p_b>>=1;p_b>0;p_b>>=1){
        ms*=ms;
        ms%=mod;
        if(m&p_b)ms*=(*this);
        ms%=mod;
    }
    return ms;
}

template<typename T> Matrix<T> Matrix<T>::pow(ll m)const{
    assert(sizeX()==sizeY());
    Matrix<T> ms(sizeX()),ma=*this;
    ms.E();
    for(int i=0;(1LL<<i)<=m;i++){
        if(m&1LL<<i)ms*=ma;
        ma*=ma;
    }
    return ms;
}

template<typename T> T& Matrix<T>::element(int a,int b){
    assert(0<=a && a<sizeX() && 0<=b && b<sizeY());
    return vec_matrix[a][b];
}
template<typename T> const vector<vector<T>>& Matrix<T>::get_vec() const{
    return vec_matrix;
}

template<typename T> T Matrix<T>::tr()const{
    assert(sizeX()==sizeY());
    int n=sizeX();
    T a=e;
    for(int i=0;i<n;i++){
        a*=vec_matrix[i][i];
    }
    return a;
}

template<typename T> Matrix<T> Matrix<T>::gauss_and_inverse(int mode)const{
    //mode: 0: gauss triangle, 1: inverse
    int n=sizeX(),m=sizeY();
    int i,j,k,l;
    vector<vector<T>> v=vec_matrix,inv(n,vector<T>(m));
    if(mode==1){
        assert(n==m);
        for(i=0;i<min(n,m);i++)inv[i][i]=e;
    }
    for(i=0,j=0;i<m;i++){
        for(k=j;k<n;k++){
            if(!same(v[k][i],zero))break;
        }
        if(k==n)continue;
        if(j<k){
            //swap j_th and k_th row
            for(l=0;l<m;l++){
                swap(v[j][l],v[k][l]);
                if(mode==1)swap(inv[j][l],inv[k][l]);
            }
        }
        for(k=j+1;k<n;k++){
            T a=v[k][i]/v[j][i];
            if(a==zero)continue;
            for(l=i+1;l<m;l++)v[k][l]-=v[j][l]*a;
            v[k][i]=zero;
            if(mode==1){
                for(l=0;l<m;l++)inv[k][l]-=inv[j][l]*a;
            }
        }
        j++;
    }
    if(mode==0)return Matrix(v);

    //fix inverse
    for(i=n-1;i>=0;i--){
        if(v[i][i]==zero)assert(false);
        for(j=0;j<i;j++){
            T a=v[j][i]/v[i][i];
            if(a==zero)continue;
            for(k=0;k<m;k++){
                inv[j][k]-=inv[i][k]*a;
            }
        }
        for(k=0;k<m;k++){
            inv[i][k]/=v[i][i];
        }
    }
    return Matrix(inv);
}

template<typename T> Matrix<T> Matrix<T>::gauss()const{
    return gauss_and_inverse(0);
}
template<typename T> T Matrix<T>::det()const{
    assert(sizeX()==sizeY());
    Matrix a=gauss();
    T s=e;
    for(int i=0;i<sizeX();i++){
        s*=a.element(i,i);
    }
    return s;
}
template<typename T> Matrix<T> Matrix<T>::inverse()const{
    return gauss_and_inverse(1);
}

template<typename T> Matrix<T> Matrix<T>::submatrix(int a,int b,int c,int d)const{
    //[a,c)*[b,d)
    assert(0<=a && a<c && c<=sizeX());
    assert(0<=b && b<d && d<=sizeY());
    Matrix<T> s(c-a,d-b);
    int i,j;
    for(i=0;i<c-a;i++){
        for(j=0;j<d-b;j++){
            s.element(i,j)=vec_matrix[a+i][b+j];
        }
    }
    return s;
}

namespace sol{
    LL mod=1e9+7;

    void solve(){
        int n,m;
        int i,j,k;
        mint p=2;
        LL a,b,c;
        Matrix<mint> ma(2),mb(2);
        ma.element(0,0)=1,ma.element(0,1)=1;
        ma.element(1,0)=2;
        mb=ma.inverse().pow(2);
        cin>>n;
        LL t=1;
        for(i=0;i<n;i++){
            cin>>a;
            t*=a%(mod-1);
            t%=mod-1;
        }
        ma=ma.pow(t);
        p=p.pow(t);
        p/=2;
        mb*=ma;
        vector<mint> va={1,0};
        va=mb*va;
        cout<<va[0]<<"/"<<p<<endl;
        
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}