#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long temp, sum = 0, maxl = 0,i;
    for (i=0;i<n;i++)
    {
        scanf("%I64d",&temp);
        sum += temp;
        maxl = max(maxl,temp);
    }
    long long ans = 2*maxl - sum + 1;
    if (ans <= 0)
    {
        cout<<0;
    }
    else
    {
        printf("%I64d",ans);
    }
    return 0;
}