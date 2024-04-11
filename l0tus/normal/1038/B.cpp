#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n>2)
    {
        printf("Yes\n");
        printf("1 %d\n",n);
        printf("%d ",n-1);
        for(int i=1; i<=n-1; i++) printf("%d ",i);
    }
    else printf("No");
}