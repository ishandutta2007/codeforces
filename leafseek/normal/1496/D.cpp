#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int a[MaxN],lef[MaxN],rig[MaxN],hei[MaxN];
char t[MaxN];
int main()
{
	register int n;
	scanf("%d",&n);
	rep(i,1,n)
		scanf("%d",&a[i]);
	if(a[1]>a[2])
		t[1]='B';
	else if(a[1]<a[2])
		t[1]='P';
	if(a[n]>a[n-1])
		t[n]='B';
	else if(a[n]<a[n-1])
		t[n]='P';
	rep(i,2,n-1)
	{
		if(a[i]>a[i-1]&&a[i]>a[i+1])
			t[i]='B';
		else if(a[i]<a[i-1]&&a[i]<a[i+1])
			t[i]='P';
		else
			t[i]='.';
	}
	t[0]=t[n+1]='x';
	rep(i,1,n)
	{
		if(t[i-1]!='.')
			lef[i]=1;
		else
			lef[i]=(lef[i-1]+1);
	}
	dow(i,n,1)
	{
		if(t[i+1]!='.')
			rig[i]=1;
		else
			rig[i]=(rig[i+1]+1);
	}
	register int Maxhei=0,cntMax=0;
	rep(i,1,n)
		if(t[i]=='B')
		{
			hei[i]=max(lef[i],rig[i]);
			Maxhei=max(Maxhei,hei[i]);
		}
	rep(i,1,n)
		if(hei[i]==Maxhei)
			++cntMax;
	if(cntMax>=2)
		printf("%d\n",0);
	else rep(i,1,n)
	{
		if(!(hei[i]==Maxhei))
			continue;
		if(!(lef[i]<=rig[i]))
			swap(lef[i],rig[i]);
		register int x=lef[i],y=rig[i];
		if(y&1)
			printf("%d\n",0);
		else if(x<y)
			printf("%d\n",0);
		else
			printf("%d\n",1);
	}
	return 0;
}