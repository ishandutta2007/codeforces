#include <bits/stdc++.h>

using namespace std;
char v[105];
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,m,i,j,mx1=0,mx2=0,s=0,cntm1=0,cnt1=0,cnt0=0;
    cin>>v;
    n=strlen(v);
    for(i=0;i<n;++i)
        if(v[i]=='1')
            ++s;
    if(n%2==1)
    {
        ++n;
        if(s>=2)
            cout<<n/2;
        else
            cout<<n/2-1;
    }
    else
        cout<<n/2;
	return 0;
}