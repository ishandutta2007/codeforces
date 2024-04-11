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
    LL i,j,k;
    LL a,b,c;
    string sa;
    cin>>n>>sa;
    for(i=0;i<=n;i++){
        a=0;
        for(j=0;j<n;j++){
            a*=2;
            a+=(int)sa[j]-(int)'0';
        }
        if((i^a)==(1LL<<n)-1)continue;
        for(j=1;j<n;j++){
            a*=2;
            a&=(1LL<<n)-1;
            a+=(int)sa[n+j-1]-(int)'0';
            if((i^a)==(1LL<<n)-1)break;
        }
        if(j<n)continue;
        sa.assign(n,'0');
        a=i;
        for(j=0;j<n;j++){
            if(a&1)sa[n-j-1]='1';
            a/=2;
        }
        cout<<sa<<endl;
        return ;
    }
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}