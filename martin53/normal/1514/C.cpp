#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;

bool in[nmax];

int main()
{
    scanf("%i",&n);

    long long p=1;

    for(int i=1;i<=n;i++)
        if(__gcd(i,n)==1)
        {
            in[i]=1;

            p=p*i%n;
        }

    if(p!=1)in[p]=0;

    vector<int> outp={};
    for(int i=1;i<=n;i++)
        if(in[i])outp.push_back(i);

    printf("%i\n",outp.size());
    for(auto w:outp)printf("%i ",w);printf("\n");

    return 0;
}