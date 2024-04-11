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

vector<int> v1;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    bool flag=false;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
        if(a==m)flag=true;
    }
    for(i=0;i<n;i++){
        if(!flag && v1[i]==0)v1[i]=m,flag=true;
    }
    if(!flag){
        cout<<"NO"<<endl;
        return 0;
    }
    for(i=0;i+1<n;i++){
        if(v1[i] && !v1[i+1])v1[i+1]=v1[i];
    }
    for(i=n-1;i-1>=0;i--){
        if(v1[i] && !v1[i-1])v1[i-1]=v1[i];
    }
    if(v1[i]==0){
        v1.assign(n,m);
        cout<<"YES"<<endl;
        array_show(v1);
        return 0;
    }
    vector<tuple<int,int,int>> vp;
    vector<int> v2(m,n),v3(m,-1);
    for(i=0;i<n;i++){
        v2[v1[i]-1]=min(v2[v1[i]-1],i);
        v3[v1[i]-1]=max(v3[v1[i]-1],i);
    }
    for(i=0;i<m;i++){
        if(v3[i]==-1)continue;
        vp.push_back(make_tuple(v2[i],i,0));
        vp.push_back(make_tuple(v3[i],i,1));
    }
    sort(vp.begin(),vp.end());
    vector<int> vf;
    for(i=0,j=0;i<n;i++){
        if(!vf.empty() && vf.back()+1>v1[i]){
            cout<<"NO"<<endl;
            return 0;
        }
        for(;j<vp.size() && get<0>(vp[j])==i;j++){
            tie(a,b,c)=vp[j];
            if(c==0){
                if(!vf.empty() && vf.back()>b){
                    cout<<"NO"<<endl;
                    return 0;
                }else vf.push_back(b);
            }else{
                if(vf.back()!=b){
                    cout<<"NO"<<endl;
                    return 0;
                }else vf.pop_back();
            }
        }
    }
    cout<<"YES"<<endl;
    array_show(v1);
    return 0;
}