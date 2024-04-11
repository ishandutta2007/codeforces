#include <bits/stdc++.h>
using namespace std;
int sp[100003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,a,b,i,n;
    cin>>n>>t;
    for(i=1;i<=n;++i)
    {
        char c;
        cin>>c;
        sp[i]=c-'a'+1+sp[i-1];
    }
    for(i=1;i<=t;++i)
    {
        cin>>a>>b;
        cout<<sp[b]-sp[a-1]<<'\n';
    }
	return 0;
}