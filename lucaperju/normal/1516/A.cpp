#include <bits/stdc++.h>
using namespace std;
int v[103];
int main()
{
    ios_base::sync_with_stdio(false);
    int q,t,m,i,j;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<n;++i)
        {
            while(v[i] && k)
            {
                --k;
                --v[i];
                ++v[n];
            }
        }
        for(i=1;i<=n;++i)
            cout<<v[i]<<' ';
        cout<<'\n';
    }
	return 0;
}