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
    int A[2222][2222];
    int B[2222][2222];
    vector<vector<int>> path,path2;
    vector<int> deg;

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin.tie(0);
        ios::sync_with_stdio(false);
        cin>>n>>m;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>A[i][j];
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>B[i][j];
            }
        }
        vector<int> vi(n),col(n);
        iota(vi.begin(),vi.end(),0);
        sort(vi.begin(),vi.end(),[&](int x,int y){
            for(i=0;i<m;i++){
                if(B[x][i]!=B[y][i])return B[x][i]<B[y][i];
            }
            return x<y;
        });
        vector<char> used(n,0);
        for(i=0;i<n;i++){
            int id=0;
            for(j=0,k=0;j<m;j++){
                for(id=vi[k];k<n && (used[id] || B[id][j]<A[i][j]);id=vi[++k]);
                if(k==n || B[id][j]!=A[i][j]){
                    cout<<-1<<endl;
                    return;
                }
            }
            col[id]=i;
            used[id]=1;
        }
        //array_show(col);
        path.assign(m,vector<int>());
        path2.assign(n,vector<int>());
        deg.assign(m,0);
        vector<int> want_change;
        for(i=0;i<n-1;i++){
            a=col[i],b=col[i+1];
            if(a>b)swap(a,b),want_change.push_back(i);
            for(j=0;j<m;j++){
                if(B[i][j]<B[i+1][j])path[j].push_back(i);
                if(B[i][j]>B[i+1][j]){
                    path2[i].push_back(j);
                    deg[j]++;
                }
            }
        }
        //array_show(col);
        queue<int> q1;
        for(i=0;i<m;i++){
            if(deg[i]==0)q1.push(i);
        }
        vector<int> vs;
        used.assign(n,0);
        while(!q1.empty()){
            a=q1.front();q1.pop();
            vs.push_back(a+1);
            for(auto num:path[a]){
                if(used[num])continue;
                used[num]=1;
                for(auto to:path2[num]){
                    deg[to]--;
                    if(deg[to]==0)q1.push(to);
                }
            }
        }
        for(auto num:want_change){
            if(!used[num]){
                cout<<-1<<endl;
                return;
            }
        }
        reverse(vs.begin(),vs.end());
        cout<<vs.size()<<endl;
        for(i=0;i<vs.size();i++){
            if(i)cout<<" ";
            cout<<vs[i];
        }
        cout<<endl;
    }
}

int main(){
    sol::solve();
}