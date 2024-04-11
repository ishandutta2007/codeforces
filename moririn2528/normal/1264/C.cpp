#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
const LL MAX=998244353;

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
    LL t[220000],t2[220000],t3[220000],t2inv[220000];

    LL calc(int a,int b){
        LL x,y,z;
        x=t[b]-t[a]-(t3[b]-t3[a])*a;
        if(x<0)x+=((-x)/MAX+1)*MAX;
        x%=MAX;
        x=x*t2inv[b]%MAX;
        return (x+b-a)%MAX;
    }
    set<int> s1;
    LL calc2(int a){
        int b,c;
        LL s=0;
        auto itr=s1.lower_bound(a),itr2=s1.upper_bound(a);
        itr--;
        while(itr!=itr2){
            b=*itr;
            itr++;
            c=*itr;
            s+=calc(b,c);
        }
        return s%MAX;
    }

    void solve(){
        int n,m;
        int i,j,k;
        LL a,b,c;
        cin>>n>>m;
        a=1,t2[0]=1;
        for(i=0;i<n;i++){
            cin>>b;
            b=divide(b,100,MAX);
            c=1-b;
            if(c<0)c+=MAX;
            t[i+1]=(t[i]+a*c%MAX*(i+1))%MAX;
            t3[i+1]=(t3[i]+a*c)%MAX;
            a*=b;
            a%=MAX;
            t2[i+1]=a;
            t2inv[i+1]=divide(1,a,MAX);
        }
        s1.insert(0),s1.insert(n);
        LL s=calc(0,n);
        for(i=0;i<m;i++){
            cin>>a;
            a--;
            s-=calc2(a);
            if(s1.find(a)==s1.end())s1.insert(a);
            else s1.erase(a);
            s+=calc2(a);
            if(s<0)s+=MAX;
            s%=MAX;
            cout<<s<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}