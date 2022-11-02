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
int n;
int main()
{
    scanf("%d", &n);
    for(int u=1; u<=n; u++){
        LL a, b, c, ans=0;
        scanf("%lld %lld %lld", &a, &b, &c);
        LL minn=min(c, min(a, b));
        c-=minn;
        a-=minn;
        b-=minn;
        ans+=minn;
        if(a==0||b==0){
            printf("%lld\n", ans);
            continue;
        }
        if(a<b)swap(a, b);
        if(a/2>=b)ans+=b;
        else if((2*a-b)%3==0&&(2*b-a)%3==0)ans+=(a+b)/3;
        else ans+=(a+b-1)/3;
        printf("%lld\n", ans);
    }
}