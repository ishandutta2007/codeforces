#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int n,g[4];
    scanf("%i%i%i%i%i",&n,&g[0],&g[1],&g[2],&g[3]);

    for(int mask=0;mask<16;mask++)
    {
        int arr[4]={0,0,0,0};
        if((mask&1))arr[0]++,arr[1]++;

        if((mask&2))arr[1]++,arr[2]++;

        if((mask&4))arr[2]++,arr[3]++;

        if((mask&8))arr[3]++,arr[0]++;

        bool ok=1;
        for(int j=0;j<4;j++)
            if(arr[j]<=g[j]&&g[j]<=arr[j]+n-2);
            else ok=0;

        if(ok)return 1;
    }

    return 0;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}