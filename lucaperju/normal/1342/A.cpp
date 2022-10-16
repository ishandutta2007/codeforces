#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int mxc=0,n,m,i,j=0,t;
	cin>>t;
	while(t--)
	{
	    long long x,y,a,b;
	    cin>>x>>y>>a>>b;
        if(x>y)
            swap(x,y);
        cout<<(y-x)*a+x*(min(2*a,b))<<'\n';
	}
    return 0;
}