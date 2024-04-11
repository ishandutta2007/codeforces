#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int bits[100];
int k;
int n;
int t;
long long x[maxn];
long long c[100];
long long cnt[100][100];
long long mod=1000000007;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%lld",&x[i]);
            k=0;
            for(long long j=0;j<60;j++) {
                if(x[i]&(1ll<<j)) {
                    bits[k++]=j;
                }
            }
            for(int p=0;p<k;p++) {
                for(int q=p+1;q<k;q++) {
                    cnt[bits[p]][bits[q]]+=1;
                }
                c[bits[p]]++;
            }
        }
        for(int p=0;p<60;p++) {
            for(int q=p+1;q<60;q++) {
                cnt[q][p]=cnt[p][q];
            }
            cnt[p][p]=c[p];
        }
        long long ans=0;
        for(int p=0;p<60;p++) {
            for(int q=0;q<60;q++) {
                long long cur=c[p]*c[p]*c[q] + c[p]*cnt[p][q]*(n-c[q]);
                cur%=mod;
                long long a=(1ll<<p)%mod;
                long long b=(1ll<<q)%mod;
                //cout<<p<<" "<<q<<" "<<cur<<" "<<c[p]<<" "<<c[q]<<endl;
                ans=(ans+((a*b)%mod)*cur)%mod;
            }
        }
        for(int p=0;p<60;p++) {
            for(int q=0;q<60;q++) {
                cnt[p][q]=0;
            }
            c[p]=0;
        }
        printf("%lld\n",ans);
        ans=0;
    }
    return 0;
}