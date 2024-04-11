#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=100005;

map<long long,long long> s;
long long a[N],ans,n,k;

int main(){
    cin>>n>>k;
    rep(i,1,n) scanf("%I64d",a+i);
    rep(i,1,n) a[i]+=a[i-1];
    long long mx=0;
    rep(i,1,n) mx=max(mx,abs(a[i]));
    mx<<=1;
    s[0ll]++;
    rep(i,1,n){
        long long t=1;
        while(t<=mx){
            ans+=s[a[i]-t];
            t*=k;
            if(k==1) break;
            if(k==-1 && t==1) break;
        }
        s[a[i]]++;
    }
    cout<<ans<<endl;
}