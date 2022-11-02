#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

void solve(){
    int t,s=0,i;
    For(i,5){
        scanf("%d",&t);
        s+=t;
    }
    if(s%5==0){
        if(s==0){
            printf("-1");
            return;
        }
        printf("%d",s/5);
    }
    else printf("-1");
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
//  while(scanf("%d",&n)!=EOF){
        solve();
//  }
    return 0;
}