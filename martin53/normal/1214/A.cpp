#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,d,e;
int main()
{
    scanf("%i%i%i",&n,&d,&e);

    int ret=n;

    for(int i=0;5*i*e<=n;i++)
    {
        int now=n-(5*i*e);
        now=now%d;
        ret=min(ret,now);
    }

    printf("%i\n",ret);
    return 0;
}