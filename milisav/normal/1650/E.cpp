#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n,d;
int a[maxn];
int b[maxn];
int tot[maxn];
bool pos(int k) {
    int cnt=0;
    for(int i=1;i<=n;i++) tot[i]=0;
    for(int i=1;i<=n;i++) {
        if(a[i]-a[i-1]-1<k) {
            tot[i-1]++;
            tot[i]++;
            cnt++;
        }
    }
    if(cnt==0) return true;
    for(int i=1;i<=n;i++) {
        if(tot[i]==cnt) {
            int l=1;
            for(int j=1;j<=n;j++) {
                if(i!=j) {
                    b[l]=a[j];
                    l++;
                }
            }
            /*for(int l=1;l<=n-1;l++) {
                cout<<k<<" "<<i<<" "<<b[l]<<endl;
            }*/
            bool ok1=true,ok2=false;
            for(int j=1;j<=n-1;j++) {
                if(b[j]-b[j-1]-1<k) ok1=false;
                if(b[j]-b[j-1]-2>=2*k) ok2=true;
            }
            if(b[1]>2*k+1 || b[n-1]<=d-(k+1)) ok2=true;
            if(ok1 && ok2) return true;
        }
    }
    return false;    
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
        }
        a[0]=0;
        int l=0;
        int r=d;
        while(l<r) {
            int m=(l+r+1)/2;
            if(pos(m)) l=m;
            else r=m-1;
        }
        printf("%d\n",l);
    }
    return 0;
}