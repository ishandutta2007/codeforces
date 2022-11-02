#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

int n;

bool read(){
    if(scanf("%d",&n)!=1) return false;
    return true;
}

long long int mx(ll int l, ll int r){
    if(l==r) return r;
    ll int t,i,m;
    int st[70],p;
    i=0;
    while((ll int)(1<<(i/2))*(ll int)(1<<(i/2))*(1<<(i%2))<=r) i++;
    t=(ll int)(1<<(i/2))*(ll int)(1<<(i/2))*(1<<(i%2))-1;
    if(t<=r&&t>=l) return t;
    p=i;
    For(i,p) st[i]=1;
    while(true){
        i=0;
        m=-1;
        while(t-(long long int)(1<<(i/2))*(long long int)(1<<(i/2))*(1<<(i%2))*st[i]>r){
            i++;
            while(st[i]==0) i++;
        }
        while(t-(ll int)(1<<(i/2))*(ll int)(1<<(i/2))*(1<<(i%2))>=l){
            m=t-(ll int)(1<<(i/2))*(ll int)(1<<(i/2))*(1<<(i%2))*st[i];
            i++;
        }
        if(m!=-1) return m;
        i--;
        while(st[i]==0) i--;
        t=t-(ll int)(1<<(i/2))*(ll int)(1<<(i/2))*(1<<(i%2));
        st[i]=0;
    }
}

void solve(){
    int i;
    long long int l,r,t;
    For(i,n){
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",mx(l,r));
    }

}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    while(read()){
        solve();
    }
    return 0;
}