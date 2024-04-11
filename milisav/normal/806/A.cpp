#include <bits\stdc++.h>
using namespace std;
long long int t;
long long int x,y,p,q;
long long int a,b;
long long int l;
int main()
{
	scanf("%lld",&t);
	while(t>0)
	{
		scanf("%lld %lld %lld %lld",&x,&y,&p,&q);
		y=y-x;
		q=q-p;
		if((p!=0 || x==0) && (q!=0 || y==0))
		{
			//cout<<p<<" "<<q<<" "<<x<<" "<<y<<endl;
			l=1;
			if(x>p) a=(x/p)+(x%p==0 ? 0 : 1);
			else a=0;
			if(y>q) b=(y/q)+(y%q==0 ? 0 : 1);
			else b=0;
			l=max(l,max(a,b));
			p=l*p;
			q=l*q;
			//cout<<l<<" "<<x<<" "<<y<<" "<<p<<" "<<q<<endl;
			printf("%lld\n",p-x+q-y);
		}
		else printf("-1\n");
		t--;
	}
	return 0;
}