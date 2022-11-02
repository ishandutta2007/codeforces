#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define llinf 8987654321987654321
#define inf 1987654321
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
int t;
LL a, b, c;
LL f1(LL st, LL fin)
{
    if(st==fin)return st;
    LL mid=(st+fin)/2+1;
    if(a+c-mid>b+mid)return f1(mid, fin);
    return f1(st, mid-1);
}
LL f2(LL st, LL fin)
{
    if(st==fin)return st;
    LL mid=(st+fin)/2+1;
    if(b+c-mid<a+mid)return f2(st, mid-1);
    return f2(mid, fin);
}
int main()
{
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a+c<=b)printf("0\n");
        else if(a>=b)printf("%lld\n", f1(0, c)+1);
        else if(a<b)printf("%lld\n", c-f2(0, c));
    }
}