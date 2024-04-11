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

int n,m;

bool read(){
    if(scanf("%d%d",&n,&m)!=2) return false;
    return true;
}

void solve(){
    map<int,int> x;
    x[n]++;
    n*=2;
    n%=m;
    while(x[n]==0){
        x[n]++;
        n*=2;
        n%=m;
    }
    if(x[0]>0) printf("Yes");
    else printf("No");

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