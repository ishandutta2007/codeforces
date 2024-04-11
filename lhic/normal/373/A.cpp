#include <iostream>

using namespace std;

int arr[20];

int main()
{
	int k;
	cin>>k;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			char a;
			cin>>a;
			if (a=='.')
				continue;
			arr[a-'0']++;
			if (arr[a-'0']>2*k)
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}