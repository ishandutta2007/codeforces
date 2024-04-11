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

long long int pow_mod(long long int a,long long int n,long long int p=1e9+7){
    //a^n mod p
    long long int b=1,t=1;
    for(;b<=n;b<<=1);
    for(b>>=1;b>0;b>>=1){
        t*=t;
        if(t>=p)t%=p;
        if(n&b)t*=a;
        if(t>=p)t%=p;
    }
    return t;
}

long long int gcd(long long int a,long long int b){
    if(a<b)gcd(b,a);
    if(b==0)return a;
    return gcd(b,a%b);
}

long long int divide(long long int a,long long int b,long long int p=1e9+7){
    // a/b mod p
    // prime:p is prime
    if(a>=p)a%=p;
    if(a<0)a+=p;
    if(b>=p)b%=p;
    if(b<0)b+=p;
    a*=pow_mod(b,p-2,p);
    return a%p;
}

namespace sol{
    LL kai[1100];
    void init(){
        kai[0]=1;
        for(int i=1;i<1e3+7;i++){
            kai[i]=kai[i-1]*i%MAX;
        }
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        vector<int> v1;
        for(i=0;i<n;i++){
            cin>>a;
            v1.push_back(a);
        }
        sort(v1.rbegin(),v1.rend());
        a=v1[m-1],b=0,c=0;
        for(i=0;i<n;i++){
            if(v1[i]==a){
                if(i<m)b++;
                else c++;
            }
        }
        cout<<divide(kai[b+c],kai[b]*kai[c])<<endl;
    }
}

int main(){
    int n,i;
    sol::init();
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}