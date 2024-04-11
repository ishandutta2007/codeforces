#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

void solve(int n){
    int i,a[101010],d,l=0,r,l1,r1;
    long long int ans=0,s=0;
    scanf("%d",&d);
    For(i,n){
        scanf("%d",&a[i]);
        if(i!=0) a[i]-=a[0];
    }
    a[0]=0;
    for(r=1;r<n;r++){
        s+=a[r]-a[r-1];
        while(s>d){
            s-=a[l+1]-a[l];
            l++;
        }
        if(l<r-1){
            ans+=(long long int)(r-l)*(r-l-1)/2;
        }
    }
    printf("%I64d\n",ans);

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