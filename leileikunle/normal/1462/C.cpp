#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int a[10]={0};
		if(n>45) cout<<-1<<endl;
		else{
			for(int i=9;i>0;i--)
			{
				if(n>i)
				{
					a[i] = i;
					n -= i;
				}else{
					a[i] = n;
					break;
				}
			}
			for(int i=1;i<=9;i++)
			{
				if(a[i])
				{
					cout<<a[i];
				}
			}
			cout<<endl;
		}
		
	}
}