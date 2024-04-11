#include<bits/stdc++.h>
using namespace std;
int t;
long long n;
int m;
long long a[200000];
long long c[84];
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %d",&n,&m);
        for(int i=0;i<m;i++) scanf("%lld",&a[i]);
        for(int i=0;i<=80;i++) c[i]=0;
        sort(a,a+m);
        long long l=1;
        int ans=0;
        int i=0;
        int k=0;
        bool pos=false;
        int r=0;
        while(l<=n || i<m) {
            r++;
            while(i<m && a[i]==l) {
                c[k]++;
                i++;
            }
            if(c[k]>0 && pos) {
                ans+=r;
                c[k]--;
                pos=false;
            }
            if(n&l) {
                if(c[k]>0) {
                    c[k]--;
                    n-=l;
                }
                else {
                    if(!pos) r=0;
                    pos=true;
                }
            }
            c[k+1]=c[k]/2;
            c[k]=c[k]%2;
            k++;
            l<<=1ll;
        }
        if(!pos) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}