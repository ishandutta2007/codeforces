#include<iostream>
using namespace std;
int num[111],n,a[111],cnt,t1,t2;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		if (!num[a[i]]) cnt++;
		num[a[i]]++;
	}
	if (cnt!=2) cout<<"NO"<<endl;
	else
	{
		for (int i=1;i<=100;i++)
		{
			if (num[i])
			{
				if (t1) t2=i;
				else t1=i;
			}
		}
		if (num[t1]!=num[t2]) cout<<"NO"<<endl;
		else cout<<"YES"<<endl<<t1<<" "<<t2<<endl;
	}
	return 0;
}