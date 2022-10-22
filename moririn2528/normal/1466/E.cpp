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

void solve(){
    int n,m;
    int i,j,k;
    LL a,b,c;
    cin>>n;
    vector<LL> v1,v2(100);
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
    }
    for(i=0;i<n;i++){
        for(j=0;j<60;j++){
            v2[j]+=(v1[i]&(1LL<<j))%MAX;
        }
    }
    for(i=0;i<60;i++){
        v2[i]%=MAX;
    }
    LL s=0;
    for(i=0;i<n;i++){
        a=0,b=0;
        for(j=0;j<60;j++){
            if(v1[i]&(1LL<<j)){
                a+=v2[j],b+=((1LL<<j)%MAX)*n%MAX;
            }else{
                b+=v2[j];
            }
        }
        a%=MAX,b%=MAX;
        s+=a*b%MAX;
    }
    s%=MAX;
    cout<<s<<endl;
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