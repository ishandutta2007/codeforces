#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

long long in[50];

string outp="codeforces";

long long prod()
{
    long long ret=1;
    for(int i=0;i<10;i++)ret=ret*in[i];
    return ret;
}

int main()
{
    long long k;
    scanf("%lld",&k);

    for(int i=0;i<10;i++)
    {
        in[i]=1;
    }

    while(prod()<k)
    {
        int mini=0;

        for(int i=0;i<10;i++)
            if(in[mini]>in[i])mini=i;

        in[mini]++;
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<in[i];j++)printf("%c",outp[i]);
    }

    printf("\n");
    return 0;
}