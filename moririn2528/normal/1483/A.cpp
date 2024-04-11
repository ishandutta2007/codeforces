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

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<vector<int>> v1(m);
        vector<int> vs(m),used(n);
        for(i=0;i<m;i++){
            cin>>a;
            for(j=0;j<a;j++){
                cin>>b;
                b--;
                v1[i].push_back(b);
            }
            if(a==1)vs[i]=b+1,used[b]++;
        }
        for(i=0,k=0;i<n;i++){
            if(used[k]<used[i])k=i;
        }
        if(used[k]>(m+1)/2){
            cout<<"NO"<<endl;
            return;
        }
        cout<<"YES"<<endl;
        for(i=0;i<m;i++){
            if(vs[i])continue;
            bool flag=false;
            for(j=0;j<v1[i].size();j++){
                if(v1[i][j]!=k)a=v1[i][j];
            }
            vs[i]=a+1;
            used[a]++;
            if(used[a]>used[k])k=a;
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