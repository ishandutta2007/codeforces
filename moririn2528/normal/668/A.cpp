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

    void solve(){
        int n,m,q;
        int i,j,k;
        int a,b,c;
        int x,y;
        cin>>n>>m>>q;
        vector<vector<P>> v1(n,vector<P>(m));
        vector<vector<int>> vs(n,vector<int>(m));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                v1[i][j]={i,j};
            }
        }
        for(k=0;k<q;k++){
            cin>>a;
            if(a==1){
                cin>>b;
                b--;
                for(i=0;i<m-1;i++){
                    swap(v1[b][i],v1[b][i+1]);
                }
            }else if(a==2){
                cin>>b;
                b--;
                for(i=0;i<n-1;i++){
                    swap(v1[i][b],v1[i+1][b]);
                }
            }else{
                cin>>a>>b>>c;
                a--,b--;
                x=v1[a][b].first,y=v1[a][b].second;
                vs[x][y]=c;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(j)cout<<" ";
                cout<<vs[i][j];
            }
            cout<<endl;
        }
        
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}