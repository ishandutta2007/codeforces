#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long pre=0,x;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld",&x);
        printf("%lld ",pre+x);
        pre=max(pre,pre+x);
    }
    printf("\n");
    return 0;
}