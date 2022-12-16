#include<bits/stdc++.h>
using namespace std;

const int MX=1e7+42;

bool on[MX];
int pref[MX];

int n,c;

bool solve()
{
    scanf("%i%i",&n,&c);

    for(int i=1;i<=c;i++)on[i]=0,pref[i]=0;

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        on[cur]=1;
    }

    for(int i=1;i<=c;i++)
        pref[i]=pref[i-1]+on[i];

    for(int i=1;i<=c;i++)
        if(on[i]==0)
            for(int j=1;i*j<=c;j++)
                if(on[j]==1)
                {
                    int l=i*j;
                    int r=min(i*j+j-1,c);

                    if(pref[r]-pref[l-1])return 0;
                }
    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}