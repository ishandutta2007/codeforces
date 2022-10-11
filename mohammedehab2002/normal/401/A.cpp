#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,x,i,ans=0,res,tmp;
	cin >> n >> x;
	for (i=0;i<n;i++)
	{
		cin >> tmp;
		ans+=tmp;
	}
	if (ans<0)
	ans*=-1;
	res=ans/x;
	if (ans%x)
	res++;
	cout << res;
}