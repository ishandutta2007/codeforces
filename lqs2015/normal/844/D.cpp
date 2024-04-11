#include<bits\stdc++.h>
using namespace std;
int n,st,x,mx,mxx,used[55555],p,val,nxt,cur;
int main()
{
	fflush(stdout);
	srand(time(0));
	cin>>n>>st>>x;
	mx=-1e9;
	for (int i=1;i<=1000;i++)
	{
		bool f=0;
		for (int j=1;j<=n;j++)
		{
			if (!used[j]) f=1;
		}
		if (!f) break;
		p=(rand()*1009)%n+1;
		while(used[p]) p=(rand()*1009)%n+1;
		cout<<"? "<<p<<endl;
		cin>>val>>nxt;
		if (val<=x)
		{
			if (mx<val) 
			{
				mx=val;
				mxx=p;
			}
		}
		else if (nxt!=-1) used[nxt]=1;
		used[p]=1;
	}
	if (mx==-1e9) cur=st;
	else cur=mxx;
	for (int i=1;i<=999;i++)
	{
		cout<<"? "<<cur<<endl;
		cin>>val>>nxt;
		if (val>=x)
		{
			cout<<"! "<<val<<endl;
			return 0;
		}
		else if (nxt==-1)
		{
			cout<<"! "<<-1<<endl;
			return 0;
		}
		else cur=nxt;
	}
	cout<<"! "<<-1<<endl;
	return 0;
}