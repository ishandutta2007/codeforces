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

void init(){
    
}

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    vector<int> v1,v2;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        v1.push_back(a);
    }
    sort(v1.begin(),v1.end());
    a=0,b=-1,c=-1;
    for(i=0;i<n;i++){
        if(b==v1[i])a++;
        else{
            if(a>=4)c=b;
            else if(a>=2)v2.push_back(b);
            b=v1[i],a=1;
        }
    }
    if(a>=4)c=b;
    else if(a>=2)v2.push_back(b);
    if(c!=-1){
        v2={c,c,c,c};
        array_show(v2);
        return;
    }
    a=0;
    double da,db;
    da=0;
    for(i=0;i+1<v2.size();i++){
        db=(double)v2[i]/v2[i+1];
        if(da<db){
            da=db,a=i;
        }
    }
    v1={v2[a],v2[a],v2[a+1],v2[a+1]};
    array_show(v1);
}

int main(){
    int n,i;
    init();
    scanf("%d",&n);
    for(i=0;i<n;i++){
        solve();
    }
}