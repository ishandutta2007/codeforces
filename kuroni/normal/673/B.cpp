#include <bits/stdc++.h>

using namespace std;

main()
{
    int A[100001],n,m,i,a,b;
    long long ans=1;
    bool check = true;
    memset(A,0,sizeof(A));
    cin>>n>>m;
    int m1 = 1, m2 = n;
    for (i=0;i<m;i++)
    {
        cin>>a>>b;
        if ((A[min(a,b)] == 2) || (A[max(a,b)] == 1)) check = false;
        A[min(a,b)] = 1;
        A[max(a,b)] = 2;
        m1 = max(m1,min(a,b));
        m2 = min(m2,max(a,b));
    }
    if ((m1 > m2) || (m = 0)) check = false;
    if (!check) cout<<0;
    else
    {
        for (i=m1+1;i<m2;i++) if (A[i] == 0) ans++;
        cout<<ans;
    }
}