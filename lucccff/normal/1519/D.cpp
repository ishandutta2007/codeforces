#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,s,x,y,z;
    long long a[5010],b[5010],c[5010];
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>a[i];
    }
    for(i=0;i<n;i++) {
        cin>>b[i];
    }
    for(i=0;i<n;i++) {
		s+=a[i]*b[i];
    }
    t=s;
    for(i=0;i<=2*n-2;i++) {
        x=i/2;
        y=(i+1)/2;
        while((x>=0)&&(y<n))
		{
			if(x==y)
			{
				z=s;
			}
			else
			{
				if(y-x==1)
				{
					z=s-a[x]*b[x]-a[y]*b[y]+a[x]*b[y]+a[y]*b[x];
				}
				else
				{
					z=z-a[x]*b[x]-a[y]*b[y]+a[x]*b[y]+a[y]*b[x];
				}
			}
			x--;
			y++;
            if (z>t) t=z;
		}
    }
    cout<<t;
    return 0;
}