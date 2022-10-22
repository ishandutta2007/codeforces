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
#include <unordered_set>
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

void init(){
    
}

void solve(){
    LL n,m,p;
    int i,j,k;
    LL a,b,c,d;
    unordered_set<LL> s1;
    cin>>n>>m>>p;
    vector<vector<int>> path(n);
    vector<char> used(n);
    vector<int> deg(n);
    for(i=0;i<m;i++){
        cin>>a>>b;
        a--,b--;
        if(a>b)swap(a,b);
        s1.insert(a*n+b);
        path[a].push_back(b);
        path[b].push_back(a);
    }
    if(p*(p-1)/2>m){
        cout<<-1<<endl;
        return;
    }
    priority_queue<P,vector<P>,greater<P>> q1;
    for(i=0;i<n;i++){
        deg[i]=path[i].size();
        if(deg[i]<p){
            q1.push(make_pair(deg[i],i));
        }
    }
    vector<int> v1;
    while(!q1.empty()){
        a=q1.top().first,b=q1.top().second,q1.pop();
        if(used[b])continue;
        if(a==p-1){
            v1.push_back(b);
            for(auto to:path[b]){
                if(!used[to])v1.push_back(to);
            }
            if(v1.size()==p){
                bool flag=true;
                for(i=0;i<p;i++){
                    for(j=i+1;j<p;j++){
                        if(v1[i]<v1[j])c=v1[i],d=v1[j];
                        else c=v1[j],d=v1[i];
                        if(s1.find(c*n+d)==s1.end()){
                            flag=false;
                            break;
                        }
                    }
                    if(!flag)break;
                }
                if(flag)break;
            }
            v1.clear();
        }
        
        used[b]=true;
        for(auto to:path[b]){
            deg[to]--;
            if(deg[to]==p-2 || deg[to]==p-1){
                q1.push(make_pair(deg[to],to));
            }
        }
    }
    if(!v1.empty()){
        cout<<2<<endl;
        for(i=0;i<v1.size();i++){
            if(i)cout<<" ";
            cout<<v1[i]+1;
        }
        cout<<endl;
        return;
    }
    for(i=0;i<n;i++){
        if(!used[i])v1.push_back(i);
    }
    if(v1.empty()){
        cout<<-1<<endl;
    }else{
        cout<<"1 "<<v1.size()<<endl;
        for(i=0;i<v1.size();i++){
            if(i)cout<<" ";
            cout<<v1[i]+1;
        }
        cout<<endl;
    }
}

int main(){
    int n,i;
    init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}