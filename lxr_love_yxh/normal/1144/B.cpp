#include<bits/stdc++.h>
using namespace std;
int n,a[2222],na,nb,b[2222],cnt,sum;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]&1) na++;
		else nb++;
	}
	if (abs(na-nb)<=1) printf("0\n");
	else if (na>nb)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]&1) b[++cnt]=a[i];
		}
		sort(b+1,b+cnt+1);
		for (int i=1;i<=na-nb-1;i++) sum+=b[i];
		printf("%d\n",sum); 
	}
	else
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]%2==0) b[++cnt]=a[i];
		}
		sort(b+1,b+cnt+1);
		for (int i=1;i<=nb-na-1;i++) sum+=b[i];
		printf("%d\n",sum); 
	}
	return 0;
}