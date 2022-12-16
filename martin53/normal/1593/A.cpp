#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        int a,b,c;
        scanf("%i%i%i",&a,&b,&c);
        printf("%i %i %i\n",max(0,max(b,c)-a+1),max(0,max(c,a)-b+1),max(0,max(a,b)-c+1));
    }
}