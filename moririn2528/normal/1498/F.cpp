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

    int n,m;
    vector<vector<int>> path,sc,sc2;
    vector<int> A;

    void dfs1(int pos,int bef){
        int i,j;
        for(auto to:path[pos]){
            if(to==bef)continue;
            dfs1(to,pos);
            for(i=0;i<2*m;i++){
                j=(i+1)%(2*m);
                sc[pos][j]^=sc[to][i];
            }
        }
        for(i=1;i<=m;i++){
            sc[pos][i]^=A[pos];
        }
    }

    void dfs2(int pos,int bef){
        int i,j,k;
        if(bef!=-1){
            for(i=0,j=1,k=2;i<2*m;i++,j++,k++){
                if(j==2*m)j=0;
                if(k==2*m)k=0;
                sc2[pos][k]^=sc2[bef][j]^sc[bef][j]^sc[pos][i];
            }
        }
        for(auto to:path[pos]){
            if(to==bef)continue;
            dfs2(to,pos);
        }
    }

    void solve(){
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        path.assign(n,vector<int>());
        sc.assign(n,vector<int>(2*m));
        sc2.assign(n,vector<int>(2*m));
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        for(i=0;i<n;i++){
            cin>>a;
            A.push_back(a);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        for(i=0;i<n;i++){
            if(i)cout<<" ";
            a=sc[i][0]^sc2[i][0];
            if(a)cout<<1;
            else cout<<0;
        }
        cout<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}