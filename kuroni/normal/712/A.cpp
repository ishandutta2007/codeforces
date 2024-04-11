#include <bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(0);
    long long A[100000], B[100000], n, i;
    cin>>n;
    for (i = 0; i < n; i++) cin>>A[i];
    for (i = 0; i < n - 1; i++) B[i] = A[i] + A[i+1];
    B[n - 1] = A[n - 1];
    for (i = 0; i < n; i++) cout<<B[i]<<" ";
}