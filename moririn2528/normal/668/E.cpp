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
#include<bitset>
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
template<typename T> istream& operator>>(istream& is,vector<T>& v1){
    int n=v1.size();
    for(int i=0;i<n;i++)is>>v1[i];
    return is;
}

namespace sol{
    const int N=1005;
    vector<vector<int>> path,rpath;
    bitset<2*N> bt[2*N];
    vector<int> vs;

    void dfs1(int pos,vector<int>& v1,vector<int>& v2,vector<char>& used,int &cnt){
        if(used[pos])return;
        used[pos]=1;
        for(auto to:path[pos]){
            dfs1(to,v1,v2,used,cnt);
        }
        v2[cnt]=pos;
        v1[pos]=cnt;
        cnt++;
    }

    void dfs2(int pos,vector<int>& v1,int id){
        if(v1[pos]!=-1)return;
        v1[pos]=id;
        for(auto to:rpath[pos]){
            dfs2(to,v1,id);
        }
    }

    void bt_create(int pos,vector<char>& used,vector<vector<int>>& path2){
        if(used[pos])return;
        used[pos]=1;
        for(auto to:path2[pos]){
            if(!used[to])bt_create(to,used,path2);
            bt[pos]|=bt[to];
        }
    }

    void topolo(queue<int>& q1,vector<int>& vi,vector<int>& deg,vector<vector<int>>& path2,int& cnt){
        int a;
        while(!q1.empty()){
            a=q1.front();q1.pop();
            vi[a]=cnt++;
            for(auto to:path2[a]){
                deg[to]--;
                if(deg[to]==0)q1.push(to);
            }
        }
    }

    int calc(vector<P>& v1,vector<P>& v2,int n){
        int a,b,c,d;
        int i,j,k;
        path.assign(2*N,vector<int>());
        rpath.assign(2*N,vector<int>());
        for(auto& node:v1){
            a=node.first,b=node.second;
            c=(N+a)%(2*N),d=(N+b)%(2*N);
            path[c].push_back(b);
            path[d].push_back(a);
            rpath[b].push_back(c);
            rpath[a].push_back(d);
        }
        vector<int> va(2*N),vb(2*N),vc(2*N,-1);
        vector<char> used(2*N);
        a=0;
        for(i=0;i<n;i++){
            dfs1(i,va,vb,used,a);
            dfs1(N+i,va,vb,used,a);
        }
        for(i=a-1,j=0;i>=0;i--){
            dfs2(vb[i],vc,j);
            if(vc[vb[i]]==j)j++;
        }
        int m=j;
        vector<vector<int>> path2(m);
        unordered_set<int> s1;
        for(i=0;i<2*N;i++){
            for(auto to:path[i]){
                a=vc[i],b=vc[to];
                if(a==b)continue;
                c=a*N*3+b;
                if(s1.find(c)!=s1.end())continue;
                s1.insert(c);
                path2[a].push_back(b);
            }
        }
        for(i=0;i<n;i++){
            if(vc[i]==vc[N+i])return -1;//2-sat doesn't have no solution
        }
        for(i=0;i<m;i++)bt[i].reset();
        for(i=0;i<2*N;i++){
            if(vc[i]!=-1)bt[vc[i]].set(i,1);
        }
        used.assign(m,0);
        for(i=0;i<m;i++)bt_create(i,used,path2);
        c=-1;
        used.assign(m,0);
        for(i=0;i<m;i++){
            if((bt[i]>>N&bt[i]).any())used[i]=1;
        }
        for(auto node:v2){
            a=node.first,b=node.second;
            a=vc[(N+a)%(2*N)],b=vc[(N+b)%(2*N)];
            if(used[a] || used[b])continue;
            if((bt[a]>>N&bt[b]).any() || (bt[b]>>N&bt[a]).any())continue;
            c=0;break;
        }
        if(c==-1)return 0;
        vector<int> deg(m);
        queue<int> q1;
        for(i=0;i<m;i++){
            for(auto to:path2[i])deg[to]++;
        }
        for(i=0;i<m;i++){
            if(i==a || i==b)deg[i]=-1;
            if(deg[i]==0)q1.push(i);
        }
        vector<int> vi(m);
        c=0;
        topolo(q1,vi,deg,path2,c);
        q1.push(a);
        if(a!=b)q1.push(b);
        deg[a]=deg[b]=0;
        topolo(q1,vi,deg,path2,c);
        vs.assign(n,0);
        for(i=0;i<n;i++){
            a=vc[i],b=vc[N+i];
            if(vi[b]<vi[a])vs[i]=1;
        }
        return 1;
    }

    void solve(){
        int n,m1,m2;
        int i,j,k;
        int a,b,c;
        vector<P> v1,v2;
        cin>>n>>m1>>m2;
        for(i=0;i<m1+m2;i++){
            cin>>a>>b;
            if(a<0)a=N-a;
            if(b<0)b=N-b;
            a--,b--;
            if(i<m1)v1.push_back({a,b});
            else v2.push_back({a,b});
        }
        a=calc(v1,v2,n);
        b=calc(v2,v1,n);
        if(!vs.empty()){
            cout<<vs<<endl;
            return;
        }
        cout<<"SIMILAR"<<endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}