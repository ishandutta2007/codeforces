#include <iostream>


using namespace std;

int arr[1000];

int n;

int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for (int i=0;i<n;i++)
	{
		if (arr[i]>0)
		{
			while (arr[i]>0)
			{
				if (i!=n-1)
				{
					cout<<"RLP";
				}
				else
				{
					cout<<"LRP";
				}
				arr[i]--;
			}
		}
		if (i!=n-1)
			cout<<"R";
	}
}