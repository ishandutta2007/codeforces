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
const LL INF=1LL<<62;
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


vector<LL> v[3];

LL check(int i,int j,int k){
    if(i<0 || v[0].size()<=i)return INF;
    if(j<0 || v[1].size()<=j)return INF;
    if(k<0 || v[2].size()<=k)return INF;
    LL a=v[0][i]-v[1][j],b=v[1][j]-v[2][k],c=v[2][k]-v[0][i];
    return a*a+b*b+c*c;
}

LL check2(int a,int b,int c){
    int i,j,k;
    LL s=INF;
    for(i=-1;i<=1;i++){
        for(j=-1;j<=1;j++){
            for(k=-1;k<=1;k++){
                s=min(s,check(a+i,b+j,c+k));
            }
        }
    }
    return s;
}

void solve(){
    int m;
    int i,j,k;
    LL a,b,c;
    int n[3];
    for(i=0;i<3;i++){
        cin>>n[i];
    }
    vector<P> va;
    for(i=0;i<3;i++){
        v[i].clear();
        for(j=0;j<n[i];j++){
            cin>>a;
            v[i].push_back(a);
            va.push_back(make_pair(a,i));
        }
        sort(v[i].begin(),v[i].end());
    }
    sort(va.begin(),va.end());
    LL s=INF;
    for(i=0,j=0,k=0,c=0;c<va.size();c++){
        if(va[c].second==0)i++;
        if(va[c].second==1)j++;
        if(va[c].second==2)k++;
        s=min({s,check2(i,j,k)});
    }
    cout<<s<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}