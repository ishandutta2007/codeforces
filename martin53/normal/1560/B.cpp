#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c;

    scanf("%i%i%i",&a,&b,&c);

    int people=2*abs(a-b);

    if(a>people||b>people||c>people)
    {
        printf("-1\n");
        return;
    }

    if(c<=people/2)printf("%i\n",c+people/2);
    else printf("%i\n",c-people/2);
}
int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}