#include<bits/stdc++.h>
#define maxn 2000000
using namespace std;
int t;
int n,m;
long long c[maxn];
long long a[maxn];
long long b[maxn];
long long ok(int i,int j) {
    int x=i*m;
    int y=j*m;
    for(int k=0;k<m;k++,x++,y++) {
        a[k]=c[x];
        b[k]=c[y];
    }
    for(int k=0;k<m-2;k++) {
        long long t=(a[k]-b[k]);
        a[k]-=t;
        a[k+1]+=2*t;
        a[k+2]-=t;
    }
    long long dif=0;
    for(int k=0;k<m;k++) {
        dif+=abs(a[k]-b[k]);
    }
    return abs(a[m-1]-b[m-1]);
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n*m;i++) {
            scanf("%d",&c[i]);
        }
        int x=0;
        int k;
        if(ok(0,1)==0) x=0;
        else {
            if(ok(0,2)==0) x=0;
            else x=1;
        }
        for(k=0;k<n;k++) {
            if(k==x) continue;
            if((ok(x,k)!=0)) {
                printf("%d %lld\n",k+1,ok(x,k));
                break;
            }
        }
    }
    return 0;
}