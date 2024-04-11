#include <bits/stdc++.h>
using namespace std;
long long ok[400003],sp[400003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	long long mxc=0,n,m,a,b,i,j=0,t;
	cin>>t;
	while(t--)
	{
	    cin>>a>>b>>n;
	    long long p=a*b;
	    long long cnt=0;
        for(i=1;i<=p;++i)
        {
            if(i%a%b!=i%b%a)
                ok[i]=1;
            else
                ok[i]=0;
            sp[i]=sp[i-1]+ok[i];
        }
        for(i=1;i<=n;++i)
        {
            long long l,r;
            cin>>l>>r;
            long long grl=(l-1)/p+1;
            long long grr=(r-1)/p+1;
            long long pl=(l-1)%p+1;
            long long pr=(r-1)%p+1;
            if(grr!=grl)
            cout<<max(0LL,grr-grl-1)*sp[p]+sp[pr]+sp[p]-sp[pl-1]<<' ';
            else
            cout<<sp[pr]-sp[pl-1]<<' ';
        }
        cout<<'\n';
	}
    return 0;
}