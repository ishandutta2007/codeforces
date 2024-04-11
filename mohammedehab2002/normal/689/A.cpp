#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	string s;
	cin >> n >> s;
	bool arr[10];
	memset(arr,false,sizeof(arr));
	for (int i=0;i<n;i++)
	arr[s[i]-'0']=true;
	if ((((arr[1] || arr[2] || arr[3]) && arr[0]) || (((arr[1] || arr[3] || arr[2]) && (arr[7] || arr[9])) && (arr[1] || arr[4] || arr[7]) && (arr[3] || arr[6] || arr[9]))))
	cout << "YES";
	else
	cout << "NO";
}