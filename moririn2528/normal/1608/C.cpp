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
    typedef tuple<int,int,int> T;

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<vector<int>> v1(2,vector<int>(n));
        vector<P> va[2];
        cin>>v1[0]>>v1[1];
        string ss(n,'0');
        for(j=0;j<2;j++){
            for(i=0;i<n;i++){
                va[j].push_back({v1[j][i],i});
            }
            sort(va[j].begin(),va[j].end());
        }
        auto calc=[&](int p)->vector<char>{
            vector<char> used(n);
            a=va[p].back().second;
            int x[2]={v1[0][a],v1[1][a]};
            int y[2]={n,n};
            used[a]=1;
            for(i=0;i<n;i++){
                j=(i+p+1)%2;
                auto itr=lower_bound(va[j].begin(),va[j].end(),P(x[j],0));
                b=itr-va[j].begin();
                for(k=b;k<y[j];k++){
                    c=va[j][k].second;
                    used[c]=1;
                    x[0]=min(x[0],v1[0][c]);
                    x[1]=min(x[1],v1[1][c]);
                }
                if(y[j]<=b)break;
                y[j]=b;
            }
            return used;
        };
        vector<char> vc1=calc(0);
        vector<char> vc2=calc(1);
        for(i=0;i<n;i++){
            if(vc1[i]&&vc2[i])ss[i]='1';
        }
        cout<<ss<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}