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

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<int> v1,va(n+5),vb(n+5);
        for(i=0;i<n;i++){
            cin>>a;
            v1.push_back(a);
        }
        for(i=0;i<n-1;i++){
            if(v1[i]<v1[i+1])va[i+1]=va[i]+1;
        }
        for(i=n-2;i>=0;i--){
            if(v1[i+1]<v1[i])vb[i]=vb[i+1]+1;
        }
        a=0;
        for(i=0;i<n;i++){
            a=max({a,va[i],vb[i]});
        }
        int s=0,t=0;
        b=0,c=0;
        for(i=0;i<n;i++){
            if(va[i]==a && vb[i]==a)t++;
            if(va[i]==a)b++;
            if(vb[i]==a)c++;
        }
        if(t==1 && b==1 && c==1 && a%2==0)s=1;
        cout<<s<<endl;
    }
}

int main(){
    sol::solve();
}