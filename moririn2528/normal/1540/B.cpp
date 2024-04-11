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

class Lca{
    // use method
    // 1. (constructer) Lca lca(n) or lca.init(n)
    // 2. lca.connect(a,b) ((a,b) \in path)
    // 3. lca.reload()
    // lca.lca(a,b): lower common ancestor
private:
    const int M=20;
    int nest=0;
    vector<vector<int>> path;
    vector<vector<int>> par;
    vector<int> depth;
    
    void init(int n){
        path.assign(n,vector<int>());
        par.assign(n,vector<int>(M,-1));
        depth.assign(n,-1);
    }

    void create_depth(int pos,int bef,int d){
        if(depth.at(pos)!=-1)return;
        depth.at(pos)=d;
        int p=bef;
        for(int i=0;i<M;i++){
            if(p==-1)break;
            par.at(pos).at(i)=p;
            p=par.at(p).at(i);
        }
        for(auto to:path.at(pos)){
            create_depth(to,pos,d+1);
        }
    }

public:
    
    Lca(int n){
        init(n);
    }
    Lca(int n,int nes){
        nest=nes;
        init(n);
    }

    int get_depth(int pos){
        return depth.at(pos);
    }
    
    void connect(int a,int b){
        path.at(a).push_back(b);
        path.at(b).push_back(a);
    }

    void reload(){
        int n=path.size();
        par.assign(n,vector<int>(M,-1));
        depth.assign(n,-1);
        create_depth(nest,-1,0);
    }

    int check_parent(int pos,int dis){
        assert(0<=dis && dis<=depth[pos]);
        if(dis==0)return pos;
        for(int i=M-1;i>=0;i--){
            if(dis<(1<<i))continue;
            dis-=1<<i;
            pos=par.at(pos).at(i);
        }
        return pos;
    }

    int lca(int a,int b){
        if(depth.at(a)<depth.at(b))swap(a,b);
        a=check_parent(a,depth.at(a)-depth.at(b));
        if(a==b)return a;
        for(int i=M-1;i>=0;i--){
            if(par.at(a).at(i)!=par.at(b).at(i)){
                a=par.at(a).at(i);
                b=par.at(b).at(i);
            }
        }
        return par.at(a).at(0);
    }

    int distance(int a,int b){
        return depth.at(a)+depth.at(b)-2*depth.at(lca(a,b));
    }
};

namespace sol{
    const int N=222;
    mint t[N][N];
    mint kai[N];
    mint conb(int a,int b){
        if(b<0 || a<b)return 0;
        return kai[a]/(kai[b]*kai[a-b]);
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        mint ma,mb;
        kai[0]=1;
        for(i=1;i<N;i++){
            kai[i]=kai[i-1]*i;
        }
        for(i=1;i<N;i++){
            ma=(mint)1/2;
            mb=ma.pow(i);
            for(j=1;j<N;j++){
                t[i][j]=t[i][j-1]+mb*conb(i+j-2,j-1);
                mb*=ma;
            }
        }
        cin>>n;
        vector<P> vp;
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            vp.push_back({a,b});
        }
        mint s=0;
        for(i=0;i<n;i++){
            Lca lca(n,i);
            for(auto node:vp){
                lca.connect(node.first,node.second);
            }
            lca.reload();
            for(j=0;j<n;j++){
                for(k=0;k<j;k++){
                    a=lca.lca(j,k);
                    b=lca.distance(a,j);
                    c=lca.distance(a,k);
                    if(b==0){
                        s++;
                        continue;
                    }
                    if(c==0)continue;
                    s+=t[b][c];
                }
            }
        }
        s/=n;
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}