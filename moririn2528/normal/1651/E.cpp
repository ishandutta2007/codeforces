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

namespace sol{

    class nodes{
    public:
        int n;
        int mi1,mi2,ma1,ma2;
        int e1,e2;

        nodes(int _n):mi1(2*_n),mi2(2*_n),ma1(0),ma2(0),n(_n){}
        
        void set(int a){
            if(a<n){
                mi1=min(mi1,a);
                ma1=max(ma1,a);
            }else{
                mi2=min(mi2,a);
                ma2=max(ma2,a);
            }
        }

        bool in(int a){
            return (mi1<=a && a<=ma1) || (mi2<=a && a<=ma2);
        }

        LL in1(int mi,int ma){// [mi,ma]
            int x1=e1,x2=e2;
            if(x1>x2)swap(x1,x2);
            if(mi<=x2 && x2<=ma)return ma-x2;
            if(mi<=x1 && x1<=ma)return ma-x1;
            return ma-mi+1;
        }
        LL in2(int mi,int ma){// [mi,ma)
            int x1=e1,x2=e2;
            if(x1>x2)swap(x1,x2);
            if(mi<=x1 && x1<ma)return x1-mi;
            if(mi<=x2 && x2<ma)return x2-mi;
            return ma-mi;
        }

        LL calc(){
            int x1=e1,x2=e2;
            if(x1>x2)swap(x1,x2);
            if(in(x1) || in(x2))return 0;
            return in1(0,mi1)*in2(ma1,n)*in1(n,mi2)*in2(ma2,2*n);
        }
        
    };

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<vector<int>> path(2*n);
        for(i=0;i<2*n;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        vector<vector<P>> vp;
        vector<char> used(2*n);
        for(i=0;i<2*n;i++){
            if(used[i])continue;
            a=i,b=path[i][0];
            vector<P> va;
            for(j=0;j<2*n && !used[a];j++){
                used[a]=1;
                va.push_back({a,b});
                a=path[b][0]+path[b][1]-a;
                swap(a,b);
            }
            vp.push_back(va);
        }
        LL s=0;
        for(auto& v:vp){
            for(i=0;i<v.size();i++){
                nodes no(n);
                no.e1=v[i].first;
                no.set(v[i].second);
                for(j=2;j<v.size();j++){
                    k=(i+j)%v.size();
                    no.set(v[k].first);
                    no.e2=v[k].second;
                    s+=j/2*no.calc();
                }
                if(i==0){
                    no.set(v[i].first);
                    no.e1=-1,no.e2=-1;
                    s+=v.size()/2*no.calc();
                }
            }
            
        }
        cout<<s<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}