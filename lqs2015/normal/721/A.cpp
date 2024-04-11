#include<iostream>
using namespace std;
int n,a[111],s,cnt;
char c;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>c;
		if (c=='W')
		{
			if (s==0) continue;
			else a[cnt++]=s;
			s=0;
		}
		else s++;
	}
	if (s>0) a[cnt++]=s;
	cout<<cnt<<endl;
	for (int i=0;i<cnt;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}