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

typedef struct node{
    int nex[26];
    int size=0;
    node(){
        memset(nex,-1,sizeof(nex));
    }
    
}node;
vector<node> vt;
vector<int> va,vb,sz;
vector<vector<int>> path;

int merge(vector<int> v,int pos,int bef=-1){
    node n1;
    vector<vector<int>> v1(26);
    int i,j;
    int a,b;
    for(auto num:v){
        if(pos==-1){
            for(i=0;i<26;i++){
                a=vt[num].nex[i];
                if(a==-1)continue;
                v1[i].push_back(a);
            }
        }else{
            if(num!=bef)v1[va[num]].push_back(num);
        }
    }
    for(i=0;i<26;i++){
        if(v1[i].empty())continue;
        if(v1[i].size()>1)n1.nex[i]=merge(v1[i],-1);
        else n1.nex[i]=v1[i][0];
        n1.size+=vt[n1.nex[i]].size;
    }
    n1.size++;
    if(pos!=-1){
        vt[pos]=n1;
        return pos;
    }
    a=vt.size();
    vt.push_back(n1);
    return a;
}

P calc(int pos,int bef){
    P s=make_pair(0,0);
    for(auto to:path[pos]){
        if(to==bef)continue;
        P pa=calc(to,pos);
        if(s.first==pa.first)s.second+=pa.second;
        if(s.first<pa.first)s=pa;
    }
    merge(path[pos],pos,bef);
    int a=vt[pos].size+vb[pos];
    if(s.first==a)s.second++;
    if(s.first<a)s=make_pair(a,1);
    return s;
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin>>n;
    string sa;
    for(i=0;i<n;i++){
        cin>>a;
        vb.push_back(a);
    }
    cin>>sa;
    for(i=0;i<n;i++){
        va.push_back((int)sa[i]-(int)'a');
    }
    path.assign(n,vector<int>());
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        a--,b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    vt.assign(n,node());
    P pa=calc(0,-1);
    cout<<pa.first<<endl;
    cout<<pa.second<<endl;
}