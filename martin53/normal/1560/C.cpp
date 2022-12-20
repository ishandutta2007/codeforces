#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;

    scanf("%i",&n);

    int k=1;

    while((k+1)*(k+1)<=n)k++;

    if(k*k==n)
    {
        printf("%i %i\n",k,1);
        return;
    }

    //cout<<"k= "<<k<<endl;
    if(k*k+k+1>=n)printf("%i %i\n",n-k*k,k+1);
    else printf("%i %i\n",k+1,(k+1)*(k+1)+1-n);
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