#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

void solve(int a){
    int i,b,c,m=0;
    scanf("%d%d",&b,&c);
    m=max(m,a+b+c);
    m=max(m,a*b+c);
    m=max(m,a+b*c);
    m=max(m,a*b*c);
    m=max(m,(a+b)*c);
    m=max(m,a*(b+c));
    printf("%d",m);
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}