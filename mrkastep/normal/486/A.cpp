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

ll n;

bool read(){
    if(scanf("%I64d",&n)!=1) return false;
    return true;
}

void solve(){
    ll ans=0;
    ans=n/2;
    if(n%2==1) ans-=n;
    printf("%I64d",ans);
}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    while(read()){
        solve();
        printf("\n\n");
    }
    return 0;
}