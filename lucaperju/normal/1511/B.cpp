#include <bits/stdc++.h>
using namespace std;
long long p[11];
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,j,n;
    cin>>t;
    p[1]=1;
    for(i=2;i<=10;++i)
        p[i]=10*p[i-1];
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        long long x,y;
        x=p[a]+p[c];
        y=p[b];
        cout<<x<<' '<<y<<'\n';
    }
	return 0;
}