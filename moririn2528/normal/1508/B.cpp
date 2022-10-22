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

    void init(){
        
    }

    void solve(){
        LL n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<int> vs;
        if(n<=60 && (1LL<<(n-1))<m){
            cout<<-1<<endl;
            return;
        }
        if(n==1){
            cout<<1<<endl;
            return;
        }
        vs.push_back(n);
        m--;
        for(i=0;i<=60 && i<n-1;i++){
            if(m&1LL<<i){
                for(j=0;j<vs.size();j++){
                    if(vs[j]==n-i)break;
                }
                vs.insert(vs.begin()+j+1,n-i-1);
            }else vs.insert(vs.begin(),n-i-1);
        }
        reverse(vs.begin(),vs.end());
        for(;i<n-1;i++){
            vs.push_back(n-1-i);
        }
        reverse(vs.begin(),vs.end());
        for(i=0;i<vs.size();i++){
            if(i)cout<<" ";
            cout<<vs[i];
        }
        cout<<endl;
    }
}

int main(){
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}