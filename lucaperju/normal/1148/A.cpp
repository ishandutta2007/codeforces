#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n,i,j,k;
    long long a,b,c;
    cin>>a>>b>>c;
    long long s=c*2LL;
    s+=min(a,b)*2LL;
    if(a!=b)
        ++s;
    cout<<s;
    return 0;
}