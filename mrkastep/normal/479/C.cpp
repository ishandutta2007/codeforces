#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

pair<int,int> a[5555];

int mn(int i){
    if(i==0) return a[0].second;
    int x=mn(i-1);
    if(x<=a[i].second) return a[i].second;
    return a[i].first;
}

void solve(int n){
    int i,k;
    For(i,n){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);
    printf("%d\n",mn(n-1));
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