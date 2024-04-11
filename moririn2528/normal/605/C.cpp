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

namespace sol{
    typedef long double type;
    typedef complex<type> C;
    type cross_product(C ca,C cb){
        return (conj(ca)*cb).imag();
    }

    type inner_product(C ca,C cb){
        return (conj(ca)*cb).real();
    }

    void convex(vector<C>& vp,C pt){
        int a,b,c;
        if(!vp.empty() && vp.back()==pt)return;
        while(vp.size()>=2){
            a=vp.size()-1;
            C ca=vp[a]-vp[a-1],cb=pt-vp[a];
            if(cross_product(ca,cb)>0)break;
            vp.pop_back();
        }
        vp.push_back(pt);
    }

    vector<C> convex_full(vector<P>& v){
        sort(v.begin(),v.end());
        vector<C> vs,vs2;
        int n=v.size();
        for(int i=0;i<n;i++){
            convex(vs,C(v[i].first,v[i].second));
        }
        for(int i=n-1;i>=0;i--){
            convex(vs2,C(v[i].first,v[i].second));
        }
        assert(!vs.empty());
        vs.pop_back();
        vs.insert(vs.end(),vs2.begin(),vs2.end());
        return vs;
    }


    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        long double x,y;
        long double s=1e9;
        cin>>n>>x>>y;
        vector<P> v1;
        for(i=0;i<n;i++){
            cin>>a>>b;
            v1.push_back({a,b});
            s=min(s,max(x/a,y/b));
        }
        v1.push_back({0,0});
        vector<C> cv=convex_full(v1);
        long double da,db,dc;
        for(i=1;i+2<cv.size();i++){
            da=x*cv[i].imag()-y*cv[i].real();
            db=x*cv[i+1].imag()-y*cv[i+1].real();
            if(da*db>=0)continue;
            dc=abs(da/db);
            da=cv[i].real()+dc*cv[i+1].real();
            s=min(s,x*(1+dc)/da);
        }
        cout<<fixed<<setprecision(20);
        cout<<s<<endl;
    }
}

int main(){
    sol::solve();
}