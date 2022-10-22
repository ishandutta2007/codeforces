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

template <typename T> class seg_tree{
private:
    static constexpr int init_N=1e5+7;
    int N;
    vector<T> seg;
    virtual T func(T a,T b){
        return max(a,b);// function
    }

    void init(int seg_n){
        assert(seg_n>=0);
        seg.assign(4*seg_n,0);
        int i;
        for(i=0;(1<<i)<seg_n;i++);
        N=(1<<i)-1;
    }

    void init_reload(){
        for(int i=N-1;i>=0;i--){
            seg[i]=func(seg[2*i+1],seg[2*i+2]);
        }
    }
    
    void update(int pos){
        T a=func(seg[pos*2+1],seg[pos*2+2]);
        if(seg[pos]==a)return;
        seg[pos]=a;
        if(pos==0)return;
        update((pos-1)/2);
    }

public:
    seg_tree(int seg_n){
        init(seg_n);
    }
    seg_tree(){
        init(init_N);
    }
    seg_tree(T *seg_t,int seg_n){
        init(seg_n);
        for(int i=0;i<seg_n;i++){
            seg[N+i]=seg_t[i];
        }
        init_reload();
    }
    seg_tree(int seg_n,T a){
        init(seg_n);
        seg.assign(4*seg_n,a);
    }

    T search(int pos){
        assert(pos>=0 && pos<=N);
        pos+=N;
        T s=seg[pos];
        while(pos>0){
            pos=(pos-1)/2;
            s=func(seg[pos],s);
        }
        return s;
    }

    void set(int a,int b,int r,int l,int x,T val){//[a,b) search
        if(a<=r && l<=b){
            seg[x]=func(seg[x],val);
            return;
        }
        int m=(r+l)/2;
        if(b<=m)return set(a,b,r,m,2*x+1,val);
        if(m<=a)return set(a,b,m,l,2*x+2,val);
        set(a,m,r,m,2*x+1,val);
        set(m,b,m,l,2*x+2,val);
    }
    void set(int a,int b,T val){
        if(a==b)return;
        assert(a<b);
        set(a,b,0,N+1,0,val);
    }
};

namespace sol{

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        char ca;
        cin>>n>>m;
        seg_tree<int> segL(m+10),segU(m+10);
        set<int> s1;
        map<int,int> m1;
        vector<pair<int,char>> v1;
        for(i=0;i<m;i++){
            cin>>a>>b>>ca;
            a--;
            v1.push_back({a,ca});
            m1[a]=1;
        }
        i=1;
        vector<int> pos={-1};
        for(auto& node:m1){
            node.second=i++;
            pos.push_back(node.first);
        }
        pos.push_back(n);
        n--;
        int p=(int)pos.size()-1;
        for(i=0;i<m;i++){
            a=m1[v1[i].first],ca=v1[i].second;
            if(s1.find(a)!=s1.end()){
                cout<<0<<endl;
                continue;
            }
            if(ca=='L'){
                b=segL.search(p-a);
                cout<<pos[a]-pos[b]<<endl;
                segU.set(b+1,a,p-a);
            }else{
                b=segU.search(a);
                cout<<pos[p-b]-pos[a]<<endl;
                segL.set(b+1,p-a,a);
            }
            s1.insert(a);
        }
    }
}

int main(){
    sol::solve();
}