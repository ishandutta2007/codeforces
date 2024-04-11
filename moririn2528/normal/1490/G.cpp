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
typedef pair<LL,LL> P;
typedef pair<LL,int> LP;
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

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        LL x,y;
        vector<LL> v1,vs;
        vector<P> va;
        cin>>n>>m;
        b=0;
        va.push_back(make_pair(0,-1));
        for(i=0;i<n;i++){
            cin>>a;
            v1.push_back(a);
            b+=a;
            if(va.back().first<b)va.push_back(make_pair(b,i));
        }
        for(i=0;i<m;i++){
            cin>>a;
            LL s=-1;
            auto itr=lower_bound(va.begin(),va.end(),make_pair(a,-2LL));
            if(itr==va.end()){
                if(b<=0){
                    vs.push_back(-1);
                    continue;
                }
                x=(a-va.back().first-1)/b+1;
                s+=x*n,a-=x*b;
                if(a<=0){
                    vs.push_back(s);
                    continue;
                }
                itr=lower_bound(va.begin(),va.end(),make_pair(a,-2LL));
            }
            assert(itr!=va.end());
            s+=itr->second+1;
            vs.push_back(s);
        }
        for(i=0;i<m;i++){
            if(i)cout<<" ";
            cout<<vs[i];
        }
        cout<<endl;
    }
}

int main(){
    int n,i;
    sol::init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}