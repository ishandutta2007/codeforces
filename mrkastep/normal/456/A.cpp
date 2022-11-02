#include <stdio.h>
#include <algorithm>
#include <vector>
#define For(i,n) for(i=0;i<n;i++)

int a[2][100000],ind[100000];

bool srt(int x,int y){
    return a[0][x]<a[0][y];
}

void solve(int n){
    int i;
    bool g=false;
    For(i,n){
        scanf("%d%d",&a[0][i],&a[1][i]);
        ind[i]=i;
    }
    std::sort(ind,ind+n,srt);
    For(i,n-1){
        if(a[0][ind[i]]<a[0][ind[i+1]]&&a[1][ind[i]]>a[1][ind[i+1]]) g=true;
    }
    if(g) printf("Happy Alex");
    else printf("Poor Alex");
}

int main() {
#pragma comment(linker, "/STACK:67108864") 
#ifndef ONLINE_JUDGE
freopen("input.txt", "rt", stdin);
freopen("output.txt", "wt", stdout);
#endif
int n,m,k;
while(scanf("%d",&n)!=EOF){
solve(n);
}
return 0;
}