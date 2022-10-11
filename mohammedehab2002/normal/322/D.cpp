#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int arr[2][105];
int arr2[105];
int main()
{
	int a,b,att=0,def=0;
	cin >> a >> b;
	for (int i=0;i<a;i++)
	{
		string s;
		int a;
		cin >> s >> a;
		if (s=="DEF")
		arr[0][def++]=a;
		else
		arr[1][att++]=a;
	}
	for (int i=0;i<b;i++)
	cin >> arr2[i];
	sort(arr[0],arr[0]+def);
	sort(arr[1],arr[1]+att);
	sort(arr2,arr2+b);
	int sum=0,sum2=0;
	for (int i=b-1;i>=0 && b-i-1<att;i--)
	{
		if (arr2[i]<=arr[1][b-i-1])
		break;
		sum+=arr2[i]-arr[1][b-i-1];
	}
	for (int i=0;i<def;i++)
	{
		for (int x=0;x<=b;x++)
		{
			if (x==b)
			{
				cout << sum;
				return 0;
			}
			if (arr2[x]>arr[0][i])
			{
				arr2[x]=0;
				break;
			}
		}
	}
	int l=att-1;
	for (int i=b-1;i>=0;i--)
	{
		if (arr2[i]==0)
		continue;
		if (l<0)
		{
			sum2+=arr2[i];
			continue;
		}
		if (arr2[i]<arr[1][l])
		{
			cout << sum;
			return 0;
		}
		sum2+=arr2[i]-arr[1][l--];
	}
	cout << max(sum,sum2);
}