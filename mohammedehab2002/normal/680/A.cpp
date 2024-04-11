#include <iostream>
#include <map>
using namespace std;
map<int,int> m;
int main()
{
	int arr[5],i,maxi=0,sum=0;
	for (i=0;i<5;i++)
	{
		cin >> arr[i];
		m[arr[i]]++;
		sum+=arr[i];
	}
	for (i=0;i<5;i++)
	{
		int tmp;
		if (m[arr[i]]>2)
		tmp=arr[i]*3;
		else if (m[arr[i]]==2)
		tmp=arr[i]*2;
		else
		tmp=0;
		maxi=max(tmp,maxi);
	}
	cout << sum-maxi;
}