#include <bits/stdc++.h.>
using namespace std;
main()
{
    ios_base::sync_with_stdio(0);
    long long n, i;
    cin>>n;
    cout<<2<<'\n';
    for (i = 2; i <= n; i++) cout<<i*(i*i+2*i)+1<<'\n';
}