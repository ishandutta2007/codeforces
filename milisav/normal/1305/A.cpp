#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int x[maxn];
int y[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&x[i]);
        for(int i=0;i<n;i++) scanf("%d",&y[i]);
        sort(x,x+n);
        sort(y,y+n);
        for(int i=0;i<n;i++) printf("%d ",x[i]);
        printf("\n");
        for(int i=0;i<n;i++) printf("%d ",y[i]);
        printf("\n");
    }
    return 0;
}