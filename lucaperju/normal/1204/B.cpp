#include <bits/stdc++.h>

using namespace std;
char v[105];
int main()
{
    ios_base::sync_with_stdio(0);
    long long l,r,n,m,i,j,mx1=0,mx2=0,s=0,cntm1=0,cnt1=0,cnt0=0;
    cin>>n>>l>>r;
    long long s1=0,s2=0;
    for(i=1;i<l;++i)
        s1+=(1<<i);
    s1+=n-(l-1);
    cout<<s1<<' ';
    --n;
    ++s2;
    for(i=1;i<=n;++i)
    {
        if(i<r)
            s2+=(1<<i);
        else
            s2+=(1<<(r-1));
    }
    cout<<s2;
	return 0;
}