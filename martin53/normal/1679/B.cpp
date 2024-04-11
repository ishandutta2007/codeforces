#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,q;

int forced;

int inp[nmax];

map<int,int> seen;

long long sum;

int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        sum+=inp[i];
        seen[i]=inp[i];
    }

    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%i",&type);

        if(type==2)
        {
            int val;
            scanf("%i",&val);

            forced=val;
            seen={};
            sum=1LL*n*forced;
        }
        else
        {
            int pos,val;
            scanf("%i%i",&pos,&val);

            if(seen.count(pos))
            {
                sum=sum-seen[pos]+val;
                seen[pos]=val;
            }
            else
            {
                sum=sum-forced+val;
                seen[pos]=val;
            }
        }

        printf("%lld\n",sum);
    }

    return 0;
}