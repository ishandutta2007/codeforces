#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int s1,s2,s3,s4;

    scanf("%i%i%i%i",&s1,&s2,&s3,&s4);

    return max(s1,s2)>min(s3,s4)&&max(s3,s4)>min(s1,s2);
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