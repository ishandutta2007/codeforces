#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long


void solve(int *z){
    int n=*z,i,a[33333],t,st[33333],p;
    scanf("%d",&t);
    For(i,n-1){
        scanf("%d",&a[i]);
        st[i]=0;
    }
    t--;
    p=0;
    while(p<n&&st[p]==0){
        st[p]=1;
        p=p+a[p];
    }
    if(st[t]==0){
        printf("NO");
    }
    else printf("YES");



}

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int n;
    while(scanf("%d",&n)==1) solve(&n);
    return 0;
}