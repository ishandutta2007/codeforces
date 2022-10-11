#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector <int> arr(6);
	vector <int> :: iterator it;
	int i;
	for (i=0;i<6;i++)
	cin >> arr[i];
	sort (arr.begin(),arr.end());
	if (count(arr.begin(),arr.end(),arr.back())>3)
	{
		for (i=0;i<4;i++)
		arr.pop_back();
		goto output;
	}
	for (it=arr.begin();it!=arr.end();it++)
	{
		if (count(arr.begin(),arr.end(),*it)>3)
		{
			for (i=0;i<4;i++)
			arr.erase(it);
		}
	}
	output: if (arr.size()==6)
	cout << "Alien";
	else if (arr[0]==arr[1])
	cout << "Elephant";
	else
	cout << "Bear";
}