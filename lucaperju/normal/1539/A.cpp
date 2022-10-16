#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long t,a,b,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        long long cntmax=b/a;
        if(n>=cntmax)
            cout<<cntmax*1LL*(n-cntmax)+(cntmax*1LL*(cntmax-1LL)/2LL)<<'\n';
        else
            cout<<(n*1LL*(n-1LL)/2LL)<<'\n';
    }
	return 0;
}