#include <bits/stdc++.h>
using namespace std;
// FWT-or: (a0,a1) (b0,b1) -> (a0,a0+a1) (b0,b0+b1) -> (a0b0,a0b0+(a0b1+a1b0+a1b1))
// (a0,a1) (b0,b1) -> (a0,a0+4a1) (b0,b0+4b1) -> (a0b0,a0b0+(4(a0b1+a1b0)+16a1b1)) -> /4 mod 4
typedef unsigned long long ull;
const int maxn=21;
int n;
ull a[(1<<maxn)|1],b[(1<<maxn)|1];
char s[(1<<maxn)|1];
inline void FWT(ull *a)
{
    int i,j,k,mid;
    for(i=1;i<=n;i++)
        for(mid=1<<(i-1),j=0;j<(1<<n);j+=1<<i)
            for(k=0;k<mid;k++)
                a[j|k|mid]=a[j|k]+(a[j|k|mid]<<2);
}
inline void IFWT(ull *a)
{
    int i,j,k,mid;
    for(i=1;i<=n;i++)
        for(mid=1<<(i-1),j=0;j<(1<<n);j+=1<<i)
            for(k=0;k<mid;k++)
                a[j|k|mid]=(a[j|k|mid]-a[j|k])>>2;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(scanf("%s",s),i=0;i<(1<<n);i++) a[i]=s[i]&3;
    for(scanf("%s",s),i=0;i<(1<<n);i++) b[i]=s[i]&3;
    FWT(a),FWT(b);
    for(i=0;i<(1<<n);i++) a[i]*=b[i];
    IFWT(a);
    for(i=0;i<(1<<n);i++) printf("%llu",a[i]&3);
    printf("\n");
    return 0;
}