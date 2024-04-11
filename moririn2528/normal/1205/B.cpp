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

    void solve(){
        const int M=60;
        int n,m;
        int i,j,k;
        LL a,b,c;
        cin>>n;
        vector<LL> v1,cnt(M);
        for(i=0;i<n;i++){
            cin>>a;
            if(a==0)continue;
            v1.push_back(a);
            for(j=0;j<M;j++){
                if(a&1LL<<j)cnt[j]++;
            }
        }
        for(i=0;i<M;i++){
            if(cnt[i]>2){
                cout<<3<<endl;
                return;
            }
        }
        n=v1.size();
        vector<vector<int>> path(n);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(v1[i]&v1[j]){
                    path[i].push_back(j);
                    path[j].push_back(i);
                }
            }
        }
        int s=INF;
        for(i=0;i<n;i++){
            vector<int> dis(n,-1);
            queue<P> q1;
            q1.push({i,-1});
            for(j=0;!q1.empty();j++){
                k=q1.size();
                while(k--){
                    a=q1.front().first,b=q1.front().second;q1.pop();
                    if(dis[a]!=-1){
                        s=min(s,dis[a]+j);
                        continue;
                    }
                    dis[a]=j;
                    for(auto to:path[a]){
                        if(to==b)continue;
                        if(dis[to]==-1)q1.push({to,b});
                    }
                }
            }
        }
        if(s==INF)s=-1;
        cout<<s<<endl;
    }
}

int main(){
    sol::solve();
}