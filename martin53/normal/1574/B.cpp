#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int a,b,c,m;

    scanf("%i%i%i%i",&a,&b,&c,&m);

    int high=a-1+b-1+c-1;
    int low=max(max(a-1-b-c,b-1-c-a),c-1-a-b);

    return low<=m&&m<=high;
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