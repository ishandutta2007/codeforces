#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    int i,a[101010],k,l=0,r,s=0,m=11111,lm,rm;
    map<int,int> c;
    scanf("%d",&k);
    For(i,n) scanf("%d",&a[i]);
    For(r,n){
        if(c[a[r]]==0) s++;
        c[a[r]]++;
        while(s>=k){
            c[a[l]]--;
            if(c[a[l]]==0) s--;
            l++;
            if(s==k-1){
                printf("%d %d\n",l,r+1);
                return;
            }
        }
    }
    printf("-1 -1\n");
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