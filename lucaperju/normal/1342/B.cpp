#include <bits/stdc++.h>
using namespace std;
char v[105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int mxc=0,n,m,i,j=0,t;
	cin>>t;
	while(t--)
	{
        cin>>v;
        n=strlen(v);
        long long s=0;
        for(i=0;i<n;++i)
        {
            s+=v[i]-'0';
        }
        if(s==0 || s==n)
        {
            cout<<v<<'\n';
            continue;
        }
        for(i=1;i<=n;++i)
        {
            cout<<"01";
        }
        cout<<'\n';
	}
    return 0;
}