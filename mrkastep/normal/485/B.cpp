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

void solve(){
    int x[1111],y[1111],i;
    long long int ans;
    For(i,n){
        scanf("%d%d",&x[i],&y[i]);
    }
    sort(x,x+n);
    sort(y,y+n);
    ans=(long long int)max(x[n-1]-x[0],y[n-1]-y[0])*max(x[n-1]-x[0],y[n-1]-y[0]);
    printf("%I64d",ans);

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