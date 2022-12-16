#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,m;
pair<int,int> inp[nmax];
int outp[nmax];

void no()
{
    printf("-1\n");
    exit(0);
}
int main()
{
    scanf("%i%i",&n,&m);

    long long sum=0;

    for(int i=1;i<=m;i++)
    {
        scanf("%i",&inp[i].first);
        inp[i].second=i;

        sum=sum+inp[i].first;
    }

    if(sum<n)no();

    int lst=n+1;

    for(int i=m;i>=1;i--)
    {
        if(lst==1)no();

        long long remain=sum-inp[i].first;

        long long p=lst-1,q=n-inp[i].first+1;

        p=min(p,q);

        p=min(p,remain+1);

        lst=p;

        outp[inp[i].second]=p;

        sum=sum-inp[i].first;
    }
    for(int i=1;i<=m;i++)printf("%i ",outp[i]);
    return 0;
}