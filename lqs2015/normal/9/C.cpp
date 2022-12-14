#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long ans[1<<10];
long long n,k,num,cnt;
int main()
{
	cin>>n;
	for (long long i=1;i<(1<<10);i++)
	{
		num=0;
		for (int j=10;j>=0;j--)
		{
			num=num*10+(((1<<j)&i)>>j);
		}		
		ans[cnt++]=num;
	}
	int q=upper_bound(ans,ans+cnt-1,n)-ans;
	cout<<q<<endl;
	return 0;
}