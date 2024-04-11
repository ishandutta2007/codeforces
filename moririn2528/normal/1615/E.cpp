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
    vector<vector<int>> path;
    vector<int> vl,vr,par;
    vector<P> vp;

    void dfs(int pos,int parent,int d,LL& t){
        vl[pos]=t++;
        par[pos]=parent;
        vp.push_back({d,pos});
        for(auto to:path[pos]){
            if(to==parent)continue;
            dfs(to,pos,d+1,t);
        }
        vr[pos]=t;
    }

    void solve(){
        LL n,m;
        int i,j,k;
        LL a,b,c;
        cin>>n>>m;
        path.resize(n);
        vl.assign(n,-1);
        vr.resize(n);
        par.assign(n,-1);
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        a=0;
        for(i=1;i<n;i++){
            if(path[i].size()==1)a++;
        }
        if(a<=m){
            LL s=0;
            for(i=a;i<=m;i++){
                s=max(s,(n-i)*i);
            }
            cout<<s<<endl;
            return;
        }
        auto op=[](P pa,P pb)->P{
            return max(pa,pb);
        };
        auto f=[](int add,P pa)->P{
            return P(pa.first+add,pa.second);
        };
        auto merge=[](int a,int b)->int{
            return a+b;
        };
        a=0;
        dfs(0,-1,0,a);
        seg_tree_lazy<P,int> seg(op,P(0,-1),f,merge,0,vp);
        LL s=1;
        vector<char> used(n);
        for(i=0;i<m;i++){
            P pa=seg.search(0,n);
            a=pa.second;
            s+=pa.first;
            for(a=pa.second;a>0 && !used[a];a=par[a]){
                used[a]=1;
                seg.apply(vl[a],vr[a],-1);
            }
        }
        b=n-s;
        c=s-m;
        s=c*(m-b);
        for(i=0;i<=b;i++){
            s=min(s,(c+i)*(m-b+i));
        }
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}