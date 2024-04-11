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

bool solve(){
    int n,m,p;
    int i,j,k;
    int a,b,c;
    vector<int> v1;
    cin>>n>>p>>m;
    for(i=0;i<m;i++){
        cin>>a;
        v1.push_back(a);
    }
    if((n-m)%(p-1))return false;
    for(i=0;i<m;i++){
        a=v1[i]-1-i;
        b=n-v1[i]-(m-1-i);
        if(a>=p/2 && b>=p/2)return true;
    }
    return false;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        if(solve())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}