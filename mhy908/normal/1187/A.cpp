#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int q;
int main()
{
    scanf("%d", &q);
    for(int u=1; u<=q; u++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", max(b-(b+c-a)+1, c-(b+c-a)+1));
    }
}