#include <bits/stdc++.h>

using namespace std;
long long a[100005],b[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long double rz=0;
        int j=0,k=0;
        for(i=1;i<=n+n;++i)
        {
            int x,y;
            cin>>x>>y;
            if(x==0)
                b[++k]=y*1LL*y;
            else
                a[++j]=x*1LL*x;
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for(i=1;i<=n;++i)
        {
            rz+=(double)sqrt(a[i]+b[i]);
        }
        cout<<fixed<<setprecision(14)<<rz<<'\n';
    }
	return 0;
}