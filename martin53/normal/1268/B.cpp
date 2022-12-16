#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long odd=0,even=0;

    for(int i=1;i<=n;i++)
    {
        long long odd_now=(inp[i])/2;
        long long even_now=inp[i]-odd_now;

        if(i%2)swap(odd_now,even_now);

        odd=odd+odd_now;
        even=even+even_now;
    }

    printf("%lld\n",min(odd,even));
    return 0;
}