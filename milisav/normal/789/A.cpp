#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int n;
int k;
int w[maxn];
int main() {
    scanf("%d %d",&n,&k);
    int cnt=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&w[i]);
        cnt=cnt+(w[i]+k-1)/k;
    }
    printf("%d\n",(cnt+1)/2);
    return 0;
}