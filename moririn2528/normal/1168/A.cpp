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
typedef pair<LL,LL> LP;
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
    vector<int> v1;

    bool check(int t){
        int a=0,b;
        for(int i=0;i<n;i++){
            if(v1[i]<=a){
                if(a-v1[i]>t)return false;
                continue;
            }
            if(v1[i]+t>=m && a<=(v1[i]+t)%m)continue;
            a=v1[i];
        }
        return true;
    }

    void solve(){
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        for(i=0;i<n;i++){
            cin>>a;
            v1.push_back(a);
        }
        int z[3]={-1,m+1};
        while(z[1]-z[0]>1){
            z[2]=(z[0]+z[1])/2;
            if(check(z[2]))z[1]=z[2];
            else z[0]=z[2];
        }
        cout<<z[1]<<endl;
    }
}

int main(){
    sol::solve();
}