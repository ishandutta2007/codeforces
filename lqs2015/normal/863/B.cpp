#include<iostream>
#include<algorithm>
using namespace std;
int a[111],n,mn,b[111],cnt,cur;
int main()
{
	cin>>n;
	mn=1e9;
	for (int i=1;i<=2*n;i++) cin>>a[i];
	for (int i=1;i<=2*n;i++)
	{
		for (int j=i+1;j<=2*n;j++)
		{
			cnt=cur=0;
			for (int k=1;k<=2*n;k++)
			{
				if (k!=i && k!=j) b[++cnt]=a[k];
			}
			sort(b+1,b+cnt+1);
			for (int k=1;k<=cnt;k+=2)
			{
				cur+=(b[k+1]-b[k]);
			}
			mn=min(mn,cur);
		}
	}
	cout<<mn<<endl;
	return 0;
}