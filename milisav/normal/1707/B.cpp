#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int t;
int n;
int a[maxn];
int cnt[maxn];
void simulate() {
    int mval=0;
    for(int i=1;i<n;i++) {
        mval=max(mval,a[i]-a[i-1]);
        cnt[a[i]-a[i-1]]++;
    }
    int k=0;
    for(int i=0;i<=mval;i++) {
        while(cnt[i]>0) {
            cnt[i]--;
            a[k]=i;
            k++;
        }
    }
    n--;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        while(n>2 && a[n-3]!=0) {
            simulate();
        }
        if(n==2) {
            printf("%d\n",a[1]-a[0]);
        }
        else {
            if(a[n-2]==0) printf("%d\n",a[n-1]);
            else {
                int x=a[n-1];
                int y=a[n-2];
                int z=n-2;
                while(z>0 && y>0) {
                    int kt=min(x/y,z);
                    x=x-kt*y;
                    if(x<y) {
                        int tmp=y;
                        y=x;
                        x=tmp;
                    }
                    z-=kt;
                }
                printf("%d\n",x-y);
            }
        }
    }
    return 0;
}