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

namespace sol{
    int n,m;
    LL t[2222][2222];

    LL get(int a,int b){
        if(a<0)a+=n;
        if(b<0)b+=n;
        return t[a%n][b%n];
    }

    void solve(){
        int i,j,k;
        LL a,b,c;
        cin>>n;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>t[i][j];
            }
        }
        vector<LL> v1;
        for(i=0;i<n;i++){
            a=get(i-1,i)*get(i,i+1)/get(i-1,i+1);
            v1.push_back(sqrt(a));
        }
        array_show(v1);
    }
}

int main(){
    sol::solve();
}