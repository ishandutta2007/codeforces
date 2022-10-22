#include<bits/stdc++.h>

using namespace std;

int a, b, c, d;
void solve()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);

    if (a+d && (a+b)%2) printf("Ya "); else printf("Tidak ");
    if (b+c && (a+b)%2) printf("Ya "); else printf("Tidak ");
    if (b+c && (a+b)%2 == 0) printf("Ya "); else printf("Tidak ");
    if (a+d && (a+b)%2 == 0) printf("Ya "); else printf("Tidak ");
    printf("\n");
}

int main()
{
    int t;
    cin>>t;

    while(t--)
        solve();
}