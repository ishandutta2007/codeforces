#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n;
int x[maxn];
int y[maxn];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&x[i],&y[i]);
    }
    if(n%2!=0) {
        printf("NO");
        return 0;
    }
    int m=n/2;
    for(int i=1;i<m;i++) {
        if(x[i]+x[i+m]!=x[i-1]+x[i+m-1] || y[i]+y[i+m]!=y[i-1]+y[i+m-1]) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}