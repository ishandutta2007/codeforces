#include <bits/stdc++.h>
using namespace std;
int v[55];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n+n;++i)
            cin>>v[i];
        sort(v+1,v+n+n+1);
        int i=1,j=n+1;
        for(int k=1;k<=n;++k)
        {
            cout<<v[i]<<' '<<v[j]<<' ';
            ++i;
            ++j;
        }
        cout<<'\n';
    }
	return 0;
}