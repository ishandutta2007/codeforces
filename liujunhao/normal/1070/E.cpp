#include <iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,k,a[200002],b[200002];
long long m;
int get(int z)
{
    long long s1=0,s=0;
    int i,s2=0,ans=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]>z) continue;
        if(s+a[i]>m) break;
        s+=a[i];
        ans++;
        s2++;
        s1+=a[i];
        if(s2==k)
        {
            if(s+s1>=m) break;
            s+=s1;
            s1=0;
            s2=0;
        }
    }
    return ans;
}
int main()
{
    int i,l,r,x,s2,ans1,ans2;
    long long s,s1;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%lld",&n,&k,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        l=b[1];
        r=b[n];
        if(r>m) r=m;
        if(l>r)
        {
        	cout<<"0 1\n";
        	continue;
		}
        while(l<r)
        {
            x=(l+r)>>1;
            s=0;
            s1=0;
            s2=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]>x) continue;
				if(s2==k)
				{
					s2=0;
					s+=s1;
					s1=0;
				}
				s+=a[i];
				s1+=a[i];
				s2++;
				if(s>m) break;
			}
			if(i<=n) r=x;
			else l=x+1;
        }
        for(i=1;i<=n;i++)
           if(b[i]>=r)
             break;
        if(i>1) i--;
		x=0;
		ans2=0;
        for(;i<=n&&x<=50;i++)
        {
        	if(i<n&&b[i]==b[i+1]) continue;
        	x++;
        	if(!ans2)
        	{
        		ans1=get(b[i]);
        		ans2=b[i];
			}
			else if(get(b[i])>ans1)
			{
				ans1=get(b[i]);
				ans2=b[i];
			}
		}
		cout<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}