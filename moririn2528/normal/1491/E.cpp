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
    vector<vector<P>> path;
    int fib[100];
    int delete_edge;

    int cnt_dfs(int pos,int bef){
        int s=1;
        for(auto node:path[pos]){
            int to=node.first;
            if(to==bef || node.second==-1)continue;
            s+=cnt_dfs(to,pos);
        }
        return s;
    }

    int cnt_fib(int pos){
        int a=cnt_dfs(pos,-1);
        if(a==0)return -1;
        for(int i=0;i<100;i++){
            if(a==fib[i])return i;
        }
        return -1;
    }

    int dfs(int pos,int bef,int n,vector<int>& next_root){
        int cnt=1;
        for(auto& node:path[pos]){
            if(node.second==-1)continue;
            int to=node.first;
            if(to==bef)continue;
            int b=dfs(to,pos,n,next_root);
            if(b==fib[n-2] || b==fib[n-1]){
                int rev=node.second;
                path[to][rev].second=-1;
                node.second=-1;
                next_root.push_back(to);
            }
            cnt+=b;
        }
        return cnt;
    }

    bool calc(int n,int pos){
        if(n<=2)return true;
        vector<int> v1={pos};
        dfs(pos,-1,n,v1);
        if(v1.size()==1 || v1.size()>3)return false;
        for(auto r:v1){
            int a=cnt_fib(r);
            if(a==-1)return false;
            if(!calc(a,r))return false;
        }
        return true;
    }

    bool solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        if(n==1)return true;
        path.assign(n,vector<P>());
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(make_pair(b,path[b].size()));
            path[b].push_back(make_pair(a,path[a].size()-1));
        }
        fib[0]=1,fib[1]=1;
        for(i=2;i<100;i++){
            fib[i]=fib[i-1]+fib[i-2];
            if(fib[i]>n)return false;
            if(fib[i]==n)break;
        }
        return calc(i,0);
    }
}

int main(){
    if(sol::solve())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}