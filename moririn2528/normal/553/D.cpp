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

vector<vector<int>> path;
int degA[110000];
int deg[110000];
bool used[110000];
const long double eps=1e-9;

int main(){
    int n,m,p;
    int i,j,k;
    int a,b,c;
    long double da,db;
    cin>>n>>m>>p;
    path.assign(n,vector<int>());
    vector<int> va;
    for(i=0;i<p;i++){
        cin>>a;
        a--;
        va.push_back(a);
    }
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        path[a].push_back(b);
        path[b].push_back(a);
        degA[a]++,degA[b]++;
        deg[a]++,deg[b]++;
    }
    for(auto pos:va){
        used[pos]=true;
        deg[pos]=0;
        for(auto to:path[pos]){
            if(used[to])continue;
            deg[to]--;
        }
    }
    typedef pair<long double,int> DP;
    priority_queue<DP,vector<DP>,greater<DP>> q1;
    for(i=0;i<n;i++){
        if(used[i])continue;
        q1.push(make_pair((long double)deg[i]/degA[i],i));
    }
    vector<int> vs;
    long double s=0;
    int itr=0;
    while(!q1.empty()){
        da=q1.top().first,a=q1.top().second;q1.pop();
        if(used[a])continue;
        if(abs(da-(long double)deg[a]/degA[a])>eps)continue;
        used[a]=true;
        if(s<da)s=da,itr=vs.size();
        vs.push_back(a);
        deg[a]=0;
        for(auto to:path[a]){
            if(used[to])continue;
            deg[to]--;
            q1.push(make_pair((long double)deg[to]/degA[to],to));
        }
    }
    a=vs.size()-itr;
    reverse(vs.begin(),vs.end());
    cout<<a<<endl;
    for(i=0;i<a;i++){
        if(i)cout<<" ";
        cout<<vs[i]+1;
    }
    cout<<endl;
}