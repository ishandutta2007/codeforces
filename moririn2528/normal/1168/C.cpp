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
    const int M=20;

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<int> v1(n),va(M,n);
        vector<vector<int>> v2(n+10,vector<int>(M,n));
        for(i=0;i<n;i++)cin>>v1[i];
        for(i=n-1;i>=0;i--){
            for(j=0;j<M;j++){
                if(~v1[i]&1<<j)continue;
                a=va[j];
                for(k=0;k<M;k++){
                    v2[i][k]=min(v2[i][k],v2[a][k]);
                }
            }
            for(j=0;j<M;j++){
                if(v1[i]&1<<j){
                    va[j]=i;
                    v2[i][j]=i;
                }
            }
        }
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            for(j=0;j<M;j++){
                if(~v1[b]&1<<j)continue;
                if(v2[a][j]<=b)break;
            }
            if(j<M)cout<<"Shi"<<endl;
            else cout<<"Fou"<<endl;
        }
    }
}

int main(){
    sol::solve();
}