#include<bits/stdc++.h>
using namespace std;
int q;
long long p[300000];
int n;
long long x,y,a,b,c;
long long k;
long long gcd(long long a,long long b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
bool possible(int m) {
    if(m==n) return true;
    int cnt = m+1;
    int i=0;
    int n1 = cnt/c;
    int n2 = cnt/a-n1;
    int n3 = cnt/b-n1;
    long long vl=0;
    for(i=0;n1;i++,n1--) vl+=(x+y)*(p[n-i-1]/100);
    if(x>y) {
        for(;n2;i++,n2--) vl+=(x)*(p[n-i-1]/100);
        for(;n3;i++,n3--) vl+=(y)*(p[n-i-1]/100);
    }
    else {
        for(;n3;i++,n3--) vl+=(y)*(p[n-i-1]/100);
        for(;n2;i++,n2--) vl+=(x)*(p[n-i-1]/100);
    }
    return vl>=k;
}
int main() {
    scanf("%d",&q);
    while(q--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%lld",&p[i]);
        }
        sort(p,p+n);
        scanf("%lld %lld",&x,&a);
        scanf("%lld %lld",&y,&b);
        c=a*b/gcd(a,b);
        scanf("%lld",&k);
        int l=0,r=n;
        while(l<r) {
            int m=(l+r)>>1;
            if(possible(m)) r=m;
            else l=m+1;
        }
        if(l==n) printf("-1\n");
        else printf("%d\n",l+1);
    }
    return 0;
}