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

LL pos[2200][2];
vector<tuple<long double,int,int>> v1;
vector<int> vt;
vector<int> vt_pos;
LL n,m;
vector<int> vs;

LL area(int a,int b,int c){
    if(a==b || a==c || b==c)return 0;
    LL x=pos[b][0]-pos[a][0];
    LL y=pos[b][1]-pos[a][1];
    LL x2=pos[c][0]-pos[a][0];
    LL y2=pos[c][1]-pos[a][1];
    LL s=abs(x*y2-y*x2);
    if(s==m)vs={a,b,c};
    return s;
}

bool check(int a,int b,int pa,int pb){
    int c;
    LL ar;
    while(abs(a-b)>1){
        c=(a+b)/2;
        ar=area(pa,pb,vt[c]);
        if(ar==m)return true;
        if(ar<m)a=c;
        else b=c;
    }
    if(area(pa,pb,vt[a])==m)return true;
    if(area(pa,pb,vt[b])==m)return true;
    return false;
}

int main(){
    int i,j,k;
    LL a,b,c;
    long double da,db;
    cin>>n>>m;
    m*=2;
    vector<P> v2;
    for(i=0;i<n;i++){
        cin>>pos[i][0]>>pos[i][1];
        v2.push_back(make_pair(pos[i][0],i));
    }
    sort(v2.begin(),v2.end());
    vt_pos.assign(n,0);
    for(i=0;i<n;i++){
        vt_pos[v2[i].second]=i;
        vt.push_back(v2[i].second);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            a=pos[i][0]-pos[j][0];
            b=pos[i][1]-pos[j][1];
            if(a==0)da=1e12;
            else da=(long double)b/a;
            v1.push_back(make_tuple(da,i,j));
        }
    }
    sort(v1.rbegin(),v1.rend());
    for(auto node:v1){
        tie(da,i,j)=node;
        if(check(vt_pos[i],0,i,j))break;
        if(check(vt_pos[i],n-1,i,j))break;

        swap(vt_pos[i],vt_pos[j]);
        swap(vt[vt_pos[i]],vt[vt_pos[j]]);
    }
    if(!vs.empty()){
        cout<<"Yes"<<endl;
        for(i=0;i<3;i++){
            cout<<pos[vs[i]][0]<<" "<<pos[vs[i]][1]<<endl;
        }
    }else cout<<"No"<<endl;
}