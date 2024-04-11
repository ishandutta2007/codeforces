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
    const int M=2e5+7;
    typedef vector<int> V1;
    typedef vector<V1> V2;
    typedef vector<V2> V3;

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        int x,y;
        cin>>n;
        V3 v1(2,V2(M,V1()));
        V2 vp(n,V1(2));
        vector<int> col(n);
        for(i=0;i<n;i++){
            cin>>a>>b;
            a--,b--;
            v1[0][a].push_back(i);
            v1[1][b].push_back(i);
            vp[i][0]=a,vp[i][1]=b;
        }
        for(i=0;i<n;i++){
            if(col[i])continue;
            col[i]=1;
            for(j=0;j<2;j++){
                a=vp[i][j],b=j,c=-1;
                while(1){
                    while(!v1[b][a].empty() && col[v1[b][a].back()])v1[b][a].pop_back();
                    if(v1[b][a].empty())break;
                    x=v1[b][a].back();v1[b][a].pop_back();
                    col[x]=c;
                    a=vp[x][1-b],b=1-b,c=-c;
                }
            }
        }
        for(i=0;i<n;i++){
            if(col[i]==1)cout<<'r';
            else cout<<'b';
        }
        cout<<endl;
    }
}

int main(){
    sol::solve();
}