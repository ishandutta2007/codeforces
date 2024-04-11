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

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        int x,y;
        cin>>n;
        vector<int> va(n),vb(n),bef(n+2);
        cin>>va>>vb;
        reverse(va.begin(),va.end());
        reverse(vb.begin(),vb.end());
        set<int> use;
        for(i=1;i<=n;i++){
            use.insert(i);
        }
        queue<int> q1;
        q1.push(0);
        for(i=0;!q1.empty();i++){
            for(j=(int)q1.size()-1;j>=0;j--){
                a=q1.front();q1.pop();
                if(a==n)break;
                b=max(a-vb[a],0);
                x=b,y=b+va[b];
                auto itr=use.lower_bound(x);
                while(itr!=use.end() && *itr<=y){
                    q1.push(*itr);
                    bef[*itr]=a;
                    use.erase(itr);
                    itr=use.lower_bound(x);
                }
            }
            if(a==n)break;
        }
        if(a!=n){
            cout<<-1<<endl;
            return;
        }
        vector<int> vs;
        while(a>0){
            vs.push_back(n-a);
            a=bef[a];
        }
        reverse(vs.begin(),vs.end());
        cout<<vs.size()<<endl;
        cout<<vs<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}