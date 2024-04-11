#include <bits/stdc++.h>
using namespace std;
main ()
{
    int A[51],t,n,k,tmp=0;
    cin>>n>>k;
    for (t = 1; t <= n; t++)
    {
        cin>>A[t];
        if (A[t] != 0) tmp++;
    }
    int i = k;
    while ((A[k] != 0)&&(A[i] == A[k])) i++;
    cout<<((A[k] == 0)?tmp:i-1);
}