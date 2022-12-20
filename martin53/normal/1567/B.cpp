#include<bits/stdc++.h>
using namespace std;

const int MX=1e6+42;

int pref_xor[MX];

int solve()
{
    int a,b;
    scanf("%i%i",&a,&b);

    if(pref_xor[a-1]==b)return a;

    if((pref_xor[a-1]^b)==a)return a+2;

    return a+1;
}

int main()
{
    for(int i=1;i<MX;i++)
        pref_xor[i]=pref_xor[i-1]^i;

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}