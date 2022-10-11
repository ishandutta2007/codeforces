#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int arr[6],i,ans=0;
	for (i=0;i<6;i++)
	cin >> arr[i];
	for (i=0;i<3;i++)
	ans+=arr[i];
	cout << (long long)(pow(ans,2)-(pow(arr[0],2)+pow(arr[2],2)+pow(arr[4],2)));
}