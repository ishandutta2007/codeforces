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

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<vector<int>> path(n,vector<int>(n,-1));
        vector<vector<int>> v1;
        vector<int> v2;
        for(i=0;i<m;i++){
            cin>>a>>b>>c;
            a--,b--;
            path[a][b]=i;
            path[b][a]=i;
            if(c==-1)continue;
            vector<int> va(m+1);
            va[m]=c%3;
            va[i]=1;
            v1.push_back(va);
            v2.push_back(1);
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                for(k=j+1;k<n;k++){
                    if(path[i][j]==-1 || path[i][k]==-1 || path[j][k]==-1)continue;
                    a=path[i][j],b=path[i][k],c=path[j][k];
                    vector<int> va(m+1,0);
                    va[a]=va[b]=va[c]=1;
                    v1.push_back(va);
                    v2.push_back(3);
                }
            }
        }
        vector<int> v3;
        for(i=0;i<m && i<v1.size();i++){
            a=i;
            for(j=i;j<v1.size();j++){
                if(v2[a]==0 || (v2[j]>0 && v2[a]>v2[j]))a=j;
            }
            if(v2[a]==0)break;
            if(a!=i){
                swap(v1[a],v1[i]);
                swap(v2[a],v2[i]);
            }
            for(j=0;j<m;j++){
                if(v1[i][j])break;
            }
            assert(j<m);
            v3.push_back(j);
            a=j;
            vector<int> va;
            b=v1[i][a];
            v1[i][a]=1;
            for(j=a+1;j<=m;j++){
                if(v1[i][j])va.push_back(j);
                v1[i][j]=v1[i][j]*b%3;
            }
            for(j=i+1;j<v1.size();j++){
                if(v1[j][a]==0)continue;
                b=3-v1[j][a];
                v1[j][a]=0;
                v2[j]--;
                for(auto id:va){
                    if(id<m && v1[j][id])v2[j]--;
                    v1[j][id]=(v1[j][id]+b*v1[i][id])%3;
                    if(id<m && v1[j][id])v2[j]++;
                }
            }
        }
        vector<int> vs(m);
        for(i--;i>=0;i--){
            a=0;
            b=v3[i];
            for(j=0;j<m;j++){
                a+=v1[i][j]*vs[j];
            }
            a%=3;
            a=(v1[i][m]-a+3)%3;
            vs[b]=a;
        }
        for(i=0;i<v2.size();i++){
            if(v2[i]==0 && v1[i][m]){
                cout<<-1<<endl;
                return;
            }
        }
        for(i=0;i<m;i++){
            if(vs[i]==0)vs[i]=3;
        }
        cout<<vs<<endl;
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