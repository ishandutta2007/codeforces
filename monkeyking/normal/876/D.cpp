#include <iostream>
#include <stdio.h>
using namespace std;
bool use[300005];

int main()
{
	int n,t,end;
	cin>>n;
	end=n-1;
	cout<<1<<' ';
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		t--;
		use[t]=true;
		while(end>=0)
		{
			if(use[end]) end--;else break;
//			cout<<end<<endl;
		}
//		cout<<"end"<<end<<endl;
		cout<<i-(n-1-end)+2<<' ';
	}
	return 0;
}