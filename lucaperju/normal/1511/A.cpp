#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,p,j,n;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int s=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            if(a==1 || a==3)
                ++s;
        }
        cout<<s<<'\n';
    }
	return 0;
}