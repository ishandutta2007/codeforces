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

    vector<vector<int>> path;
    vector<int> used,fliped;
    
    void dfs(int pos,int bef,int& a,int& b,int c){
        if(used[pos])return;
        used[pos]=1;
        for(auto to:path[pos]){
            if(to==bef)continue;
            dfs(to,pos,a,b,1-c);
        }
        if(c==fliped[pos])a++;
        else b++;
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c,d;
        cin>>n;
        typedef tuple<int,int,int> T;
        vector<T> v1;
        for(i=0;i<n;i++){
            cin>>a>>b;
            a--,b--;
            if((a<n && b<n) || (a>=n && b>=n)){
                cout<<-1<<endl;
                return;
            }
            c=0;
            if(a>=n)swap(a,b),c=1;
            v1.push_back({a,b,c});
        }
        sort(v1.begin(),v1.end());
        map<int,int> m1;
        path.resize(n);
        fliped.resize(n);
        for(i=0;i<n;i++){
            tie(ignore,a,b)=v1[i];
            a-=n;
            fliped[i]=b;
            c=-1;
            while(!m1.empty() && m1.begin()->first<a){
                b=m1.begin()->second;
                if(b==-1){
                    cout<<-1<<endl;
                    return;
                }
                path[i].push_back(b);
                path[b].push_back(i);
                if(c==-1)c=m1.begin()->first,d=b;
                m1.erase(m1.begin());
            }
            if(c!=-1){
                m1[a]=-1;
                m1[c]=d;
            }else m1[a]=i;
        }
        used.assign(n,0);
        int s=0;
        for(i=0;i<n;i++){
            if(used[i])continue;
            a=0,b=0;
            dfs(i,-1,a,b,0);
            s+=min(a,b);
        }
        cout<<s<<endl;
    }
}

int main(){
    sol::solve();
}