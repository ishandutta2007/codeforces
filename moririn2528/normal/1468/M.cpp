#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

void init(){
    
}

int t[220000];
int t2[220000];
int t_cnt=10;
const int B=100;

void solve(){
    int n,m;
    int i,j,k;
    LL a,b,c,d;
    map<int,int> m1;
    cin>>n;
    vector<vector<int>> v1(n);
    for(i=0,c=0;i<n;i++){
        cin>>m;
        for(j=0;j<m;j++){
            cin>>a;
            if(m1.find(a)==m1.end())m1[a]=c++;
            a=m1[a];
            v1[i].push_back(a);
        }
    }
    for(i=0;i<n;i++){
        if(v1[i].size()<B)continue;
        t_cnt++;
        for(j=0;j<v1[i].size();j++){
            t[v1[i][j]]=t_cnt;
        }
        for(j=0;j<n;j++){
            if(i==j)continue;
            a=0;
            for(k=0;k<v1[j].size();k++){
                if(t[v1[j][k]]==t_cnt)a++;
            }
            if(a>=2){
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
        }
    }
    vector<vector<P>> vt(m1.size());
    for(i=0;i<n;i++){
        if(v1[i].size()>=B)continue;
        for(j=0;j<v1[i].size();j++){
            for(k=j+1;k<v1[i].size();k++){
                a=v1[i][j],b=v1[i][k];
                if(a>b)swap(a,b);
                vt[a].push_back(make_pair(b,i));
            }
        }
    }
    for(auto &v:vt){
        t_cnt++;
        for(auto num:v){
            if(t[num.first]==t_cnt){
                cout<<t2[num.first]+1<<" "<<num.second+1<<endl;
                return;
            }
            t[num.first]=t_cnt;
            t2[num.first]=num.second;
        }
    }
    cout<<-1<<endl;
    
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