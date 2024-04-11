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

template<typename T> class Compress{
    //Compress<int> ca({5,1,2,3});
    //ca.id(5) //=3
private:
    vector<T> vec;
    vector<int> id_perm;//v1 index -> vec index
public:
    void init(const vector<T>& v1){
        int n=v1.size();
        int i,j;
        id_perm.assign(n,-1);
        vector<pair<T,int>> va;
        for(i=0;i<n;i++){
            va.push_back({v1[i],i});
        }
        sort(va.begin(),va.end());
        vec.clear();
        for(i=0,j=-1;i<n;i++){
            if(vec.empty() || vec.back()!=va[i].first){
                vec.push_back(va[i].first);
                j++;
            }
            id_perm[va[i].second]=j;
        }
    }

    Compress(const vector<T> v1){
        init(v1);
    }

    vector<int> get_id_perm()const{
        return id_perm;
    }

    int id(const T a){
        auto itr=lower_bound(vec.begin(),vec.end(),a);
        assert(itr!=vec.end());//return -1?
        assert(*itr==a);
        return itr-vec.begin();
    }
};

template<typename T> class bit{
private:
    vector<T> bit_vec;
    int bit_N=20;

    T bit_comp(T a,T b){
        return max(a,b);
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

template <typename T,typename F> class seg_tree_lazy{
    //T: value type, F: function type
    //value: monoid
    //function: linear,closed
private:
    function<T(T,T)> op;
    T e;
    function<T(F,T)> func;//f(x)
    function<F(F,F)> merge_func;//f*g
    F id;
    int N,bit_N,n=-1;
    vector<T> seg;
    vector<F> lazy_func;

    void init(){
        assert(n>=0);
        int i;
        for(i=0;(1<<i)<n;i++);
        N=(1<<i)-1;
        bit_N=i;
        seg.assign(2*(N+1),e);
        lazy_func.assign(2*(N+1),id);
    }

    void init_reload(){
        for(int i=N-1;i>=0;i--){
            seg[i]=op(seg[2*i+1],seg[2*i+2]);
        }
    }

    T get_applied_value(int pos){
        assert(0<=pos && pos<(int)seg.size());
        return func(lazy_func[pos],seg[pos]);
    }

    void apply_lazy_func(int pos){
        seg[pos]=func(lazy_func[pos],seg[pos]);
        if(pos>=N){
            lazy_func[pos]=id;
            return;
        }
        lazy_func[2*pos+1]=merge_func(lazy_func[pos],lazy_func[2*pos+1]);
        lazy_func[2*pos+2]=merge_func(lazy_func[pos],lazy_func[2*pos+2]);
        lazy_func[pos]=id;
    }

public:
    seg_tree_lazy(function<T(T,T)> _op,T _e,function<T(F,T)> _func,function<F(F,F)> _merge_func,F _id,int _n)
        :op(_op),e(_e),func(_func),merge_func(_merge_func),id(_id),n(_n){
        init();
    }
    seg_tree_lazy(function<T(T,T)> _op,T _e,function<T(F,T)> _func,function<F(F,F)> _merge_func,F _id,int _n,T a)
        :op(_op),e(_e),func(_func),merge_func(_merge_func),id(_id),n(_n){
        init();
        for(int i=0;i<n;i++){
            seg[N+i]=a;
        }
        init_reload();
    }
    seg_tree_lazy(function<T(T,T)> _op,T _e,function<T(F,T)> _func,function<F(F,F)> _merge_func,F _id,vector<T>& vec)
        :op(_op),e(_e),func(_func),merge_func(_merge_func),id(_id){
        n=vec.size();
        init();
        for(int i=0;i<n;i++){
            seg[N+i]=vec[i];
        }
        init_reload();
    }

    void set(int pos,T a){
        assert(pos>=0 && pos<=N);
        int p=0;
        for(int i=bit_N-1;i>=0;i--){
            apply_lazy_func(p);
            if(~pos&1<<i)p=2*p+1;
            else p=2*p+2;
        }
        pos+=N;
        seg[pos]=a;
        lazy_func[pos]=id;
        for(int i=0;i<100 && pos>0;i++){
            pos=(pos-1)/2;
            a=op(get_applied_value(2*pos+1),get_applied_value(2*pos+2));
            if(seg[pos]==a)return;
            seg[pos]=a;
        }
        assert(pos==0);
    }

    T search(int a,int b,int r,int l,int x){//[a,b) search
        if(a<=r && l<=b)return get_applied_value(x);
        int m=(r+l)/2;
        if(b<=m)return func(lazy_func[x],search(a,b,r,m,2*x+1));
        if(m<=a)return func(lazy_func[x],search(a,b,m,l,2*x+2));
        return func(lazy_func[x],op(search(a,m,r,m,2*x+1),search(m,b,m,l,2*x+2)));
    }
    T search(int a,int b){
        assert(a<=b);
        if(a==b)return e;
        return search(a,b,0,N+1,0);
    }

    void apply(int a,int b,F f,int r,int l,int x){//[a,b) add
        if(a<=r && l<=b){
            lazy_func[x]=merge_func(f,lazy_func[x]);
            return;
        }
        int m=(r+l)/2;
        apply_lazy_func(x);
        if(a<m)apply(a,min(m,b),f,r,m,2*x+1);
        if(m<b)apply(max(m,a),b,f,m,l,2*x+2);
        seg[x]=op(get_applied_value(2*x+1),get_applied_value(2*x+2));
    }
    void apply(int a,int b,F f){
        assert(a<=b);
        if(a==b)return;
        apply(a,b,f,0,N+1,0);
    }

    int max_right(function<bool(T)>& g,int pos,int l,int r,int x,T& y,F f){
        //suppose that S is return value, g(func(pos,..,S-1))=true,g(func(pos,..,S))=false
        //g(func(pos,..,i))=true iff i<S
        f=merge_func(f,lazy_func[x]);
        T val=op(y,func(f,seg[x]));
        if(r<=pos)return -1;
        if(pos<=l && g(val)){
            y=val;
            return r;
        }
        if(l+1==r)return l;
        int m=(l+r)/2;
        apply_lazy_func(x);
        if(pos<m){
            int s=max_right(g,pos,l,m,2*x+1,y,f);
            if(s<m)return s;
        }
        return max_right(g,pos,m,r,2*x+2,y,f);
    }
    int max_right(function<bool(T)> g,int pos){
        T y=e;
        int s=max_right(g,pos,0,N+1,0,y,id);
        return min(s,n);
    }

    int min_left(function<bool(T)>& g,int pos,int l,int r,int x,T& y,F f){
        //suppose that S is return value, g(func(S,..,pos-1))=true,g(func(S-1,..,pos-1))=false
        //g(func(i,..,pos-1))=true iff S<=i
        int s;
        f=merge_func(f,lazy_func[x]);
        T val=op(func(f,seg[x]),y);
        if(pos<=l)return n;
        if(r<=pos && g(val)){
            y=val;
            return l;
        }
        if(l+1==r)return r;
        int m=(l+r)/2;
        if(m<pos){
            s=min_left(g,pos,m,r,2*x+2,y,f);
            if(m<s)return s;
        }
        return min_left(g,pos,l,m,2*x+1,y,f);
    }
    int min_left(function<bool(T)> g,int pos){
        assert(pos>=0);
        if(pos==0)return 0;
        T y=e;
        return min_left(g,pos,0,N+1,0,y);
    }
};

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        int x,y;
        cin>>n>>m;
        vector<P> v1,v2;
        vector<int> va;
        for(i=0;i<n;i++){
            cin>>a>>b;
            if(a<m)continue;
            j=v1.size();
            v1.push_back({a,b});
            if(a<b)v2.push_back({a,j});
            else v2.push_back({b,-j});
            va.push_back(a),va.push_back(b);
        }
        Compress<int> ca(va);
        n=v1.size();
        for(i=0;i<n;i++){
            a=v1[i].first,b=v1[i].second;
            v1[i]={ca.id(a),ca.id(b)};
        }
        sort(v2.begin(),v2.end());
        seg_tree_lazy<int,P> seg([](int a,int b)->int{
            return max(a,b);
        },0,[](P b,int a)->int{
            return max(a+b.first,b.second);
        },[](P a,P b)->P{
            return {a.first+b.first,max(a.second,b.second+a.first)};
        },{0,0},2*n);
        for(i=0;i<n;i++){
            a=abs(v2[i].second);
            x=v1[a].first,y=v1[a].second;
            if(x<=y){
                b=seg.search(0,x+1);
                seg.set(y,b+1);
            }else{
                b=seg.search(0,y+1);
                seg.set(y,b+1);
                seg.apply(y+1,x+1,{1,b+1});
            }
        }
        cout<<seg.search(0,2*n)<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}