#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k;

int phi[nmax];

long long outp;

int main()
{
    scanf("%i%i",&n,&k);

    if(k<=2)
    {
        printf("%i\n",3*k);
        return 0;
    }

    long long outp=6;

    k=k-2;

    for(int i=2;i<=n;i++)phi[i]=i;

    for(int i=2;i<=n;i++)
    {
        if(i==phi[i])
        {
            for(int j=i;j<=n;j=j+i)
                phi[j]=phi[j]/i*(i-1);
        }

    }

    //for(int i=5;i<=n;i++)cout<<i<<" -> "<<phi[i]<<endl;

    vector<int> active={};

    for(int i=5;i<=n;i++)
        active.push_back(phi[i]);

    sort(active.begin(),active.end());

    for(int i=0;i<k;i++)
        outp+=active[i];

    printf("%lld\n",outp);
    return 0;
}