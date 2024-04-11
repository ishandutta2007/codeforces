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
typedef pair<LL,LL> P;
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

long long int gcd(long long int a,long long int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

namespace sol{
    vector<vector<LL>> path;
    vector<LL> beu;

    LL dfs(int pos,int bef,vector<P>& v){
        vector<P> v1;
        LL a,b;
        LL s=0;
        for(auto node:v){
            a=gcd(node.first,beu[pos]);
            if(!v1.empty() && v1.back().first==a)v1.back().second+=node.second;
            else v1.push_back(make_pair(a,node.second));
            s+=a*node.second%MAX;
        }
        if(!v1.empty() && v1.back().first==beu[pos])v1.back().second++;
        else v1.push_back(make_pair(beu[pos],1));
        s+=beu[pos];
        s%=MAX;
        for(auto to:path[pos]){
            if(to==bef)continue;
            s+=dfs(to,pos,v1)%MAX;
        }
        return s%MAX;
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        vector<P> v1;
        cin>>n;
        beu.assign(n,0);
        path.assign(n,vector<LL>());
        for(i=0;i<n;i++){
            cin>>beu[i];
        }
        for(i=0;i<n-1;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        cout<<dfs(0,-1,v1)%MAX<<endl;
    }
}

int main(){
    sol::solve();
}