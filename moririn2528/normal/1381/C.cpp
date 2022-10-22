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

void init(){
    
}

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    int x,y;
    cin>>n>>x>>y;
    vector<vector<int>> v1(n+1);
    for(i=0;i<n;i++){
        cin>>a;
        a--;
        v1[a].push_back(i);
    }
    m=(n-x)/2;
    c=0;
    for(i=0;i<n+1;i++){
        if(v1[i].empty())c=i;
    }
    vector<int> vs(n,c);
    a=0;
    for(i=0;i<n+1;i++){
        while(v1[i].size()>m && a<x){
            b=v1[i].back();
            v1[i].pop_back();
            a++;
            vs[b]=i;
        }
    }
    for(i=0,j=-1;i<n+1;i++){
        while(!v1[i].empty() && a<x){
            b=v1[i].back();
            v1[i].pop_back();
            a++;
            vs[b]=i;
        }
        if(v1[i].size()>m)j=i;
    }
    if(j!=-1){
        a=v1[j].size();
        a=2*a-(n-x);
        if(a>n-y){
            cout<<"NO"<<endl;
            return;
        }
        a=y-x;
        for(i=0,k=0;i<n+1;i++){
            if(i==j)continue;
            for(auto num:v1[i]){
                if(a>0)vs[num]=j,a--;
                if(a>0)vs[v1[j][k]]=i,a--,k++;
            }
        }
    }else{
        a=y-x;
        vector<int> v2;
        for(i=0;i<n+1;i++){
            for(auto num:v1[i])v2.push_back(num);
        }
        for(i=0,k=m;i<n+1;i++){
            for(j=0;j<v1[i].size();j++,k++){
                if(k>=v2.size())k-=v2.size();
                if(a>0)vs[v2[k]]=i,a--;
            }
        }
    }

    cout<<"YES"<<endl;
    for(i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<vs[i]+1;
    }
    cout<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}