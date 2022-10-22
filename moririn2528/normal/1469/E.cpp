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

int used_cnt=1;
int used[1<<21];

void solve(){
    int n,m;
    int i,j,k;
    int a,b,c;
    const int B=20;
    string sa;
    cin>>n>>m;
    cin>>sa;
    vector<int> su(n+10,0),v1(n);
    for(i=0;i<n;i++){
        v1[i]=sa[i]-'0';
        su[i+1]=su[i]+v1[i];
    }
    used_cnt++;
    for(i=0;i<=n-m;i++){
        if(m>B){
            if(su[i]+m-B!=su[i+m-B])continue;
            j=m-B;
        }else j=0;
        a=0;
        for(;j<m;j++){
            a*=2;
            a+=1-v1[i+j];
        }
        used[a]=used_cnt;
    }
    for(i=0;i<(1<<20);i++){
        if(used[i]!=used_cnt)break;
    }
    if(m<=B && i>=(1<<m)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    a=i;
    string ss(m,'0');
    for(i=0;i<min(m,B);i++){
        ss[m-i-1]=a%2+'0';
        a/=2;
    }
    cout<<ss<<endl;
}

int main(){
    int n,i;
    init();
    cin>>n;
    for(i=0;i<n;i++){
        solve();
    }
}