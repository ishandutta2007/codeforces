#include<bits/stdc++.h>
using namespace std;

const int MX=52;

int n,q,pos[MX];

int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        if(pos[cur]==0)pos[cur]=i;
    }

    for(int i=1;i<=q;i++)
    {
        int cur;
        scanf("%i",&cur);

        printf("%i\n",pos[cur]);

        for(int j=1;j<MX;j++)
            if(pos[j]<pos[cur])pos[j]++;

        pos[cur]=1;
    }


    return 0;
}