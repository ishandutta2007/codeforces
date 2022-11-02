#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <time.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long




void solve(){
    vector<int> t[3];
    int i,n,a;
    scanf("%d",&n);
    For(i,n){
        scanf("%d",&a);
        t[a-1].pb(i+1);
    }
    a=min(min(t[0].size(),t[1].size()),t[2].size());
    printf("%d\n",a);
    For(i,a) printf("%d %d %d\n",t[0][i],t[1][i],t[2][i]);

        


}




int main(){
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    solve();
    
    return 0;
}