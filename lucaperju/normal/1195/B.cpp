#include <bits/stdc++.h>

using namespace std;
int fv[1003];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j,cnt=0,k=0,mn=2,n,m,is,js,ib,jb;
    cin>>n>>k;
    int sc=0,pz=1;
    while(sc-n<k)
    {
        sc+=pz;
        --n;
        ++pz;
    }
    cout<<n;
    return 0;
}