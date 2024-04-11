#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 2000000
using namespace std;
long long mod=1000000007;
long long step(long long a,long long b) {
    if(b==0ll) return 1ll;
    if(b&1ll) return (a*step(a,b-1ll))%mod;
    else return step((a*a)%mod,b>>1ll);
}
long long inverse(long long a) {
    return step(a,mod-2);
}
int t;
long long n,p;
vector<int> f;
vector<int> s;
long long a[maxn];
int main() {
    scanf("%d",&t);
    while(t--) {
        f.clear();
        s.clear();
        scanf("%lld %lld",&n,&p);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        sort(a,a+n);
        reverse(a,a+n);
        long long nec=0;
        for(int i=0;i<n;i++) {
            if(nec==0) {
                f.push_back(i);
                nec=1;
            }
            else {
                if(nec>=n) {
                    s.push_back(i);
                    continue;
                }
                long long ti=a[i-1]-a[i];
                while(ti>0 && nec<=1e9 && p!=1) {
                    ti--;
                    nec*=p;
                }
                s.push_back(i);
                nec--;
            }
        }
        long long a1=0,a2=0;
        for(auto i:f) a1=(a1+step(p,a[i]))%mod;
        for(auto i:s) a2=(a2+step(p,a[i]))%mod;
        long long ans=(a1-a2+mod)%mod;
        printf("%lld\n",ans);
    }
	return 0;
}