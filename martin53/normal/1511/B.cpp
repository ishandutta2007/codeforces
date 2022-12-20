#include<bits/stdc++.h>
using namespace std;

int pwr[20];

void solve()
{
    int a,b,c;
    scanf("%i%i%i",&a,&b,&c);

    a--;
    b--;
    c--;

    if(a<=b)printf("%i %i\n",pwr[c]*pwr[a-c],pwr[c]*(pwr[b-c]+1));
    else printf("%i %i\n",pwr[c]*(pwr[a-c]+1),pwr[c]*pwr[b-c]);
}

int main()
{
    pwr[0]=1;
    for(int i=1;i<=9;i++)pwr[i]=pwr[i-1]*10;

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}