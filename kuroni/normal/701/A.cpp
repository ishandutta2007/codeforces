#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
main()
{
    int n, i, a[100], sum=0, j;
    bool c[100];
    memset(c,false,sizeof(c));
    for(cin>>n,i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    sum *= 2;
    i = 0;
    while (i < n)
    {
        if (c[i]) i++; else
        {
            for (j = i + 1; j < n; j++) if ((a[i] + a[j] == sum/n)&&(!c[j])) {cout<<i+1<<" "<<j+1<<endl;c[i] = true;c[j] = true; break;}
        }
    }
}