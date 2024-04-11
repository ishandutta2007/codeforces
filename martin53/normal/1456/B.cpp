#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

int pref[nmax];

int ask(int l,int r)
{
    return pref[r]^pref[l-1];
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)pref[i]=pref[i-1]^inp[i];

    for(int sum=1;sum<=n;sum++)
    {
        for(int l1=1;l1<=n;l1++)
            for(int r1=l1;r1-l1<=sum&&r1<n;r1++)
            {
                int l2=r1+1;

                int r2=sum-(r1-l1)+l2;

                if(r2>n)continue;

                if(ask(l1,r1)>ask(l2,r2))
                {
                    printf("%i\n",sum);
                    exit(0);
                }
            }

    }

    printf("-1\n");

    return 0;
}