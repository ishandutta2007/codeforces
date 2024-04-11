#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int arr[4],i;
    long long a,b,c,d,mini=1000000000000000;
    char s[3];
    for (i=0;i<4;i++)
    cin >> arr[i];
    for (i=0;i<3;i++)
    cin >> s[i];
    sort (arr,arr+4);
    do{
    	c=arr[0];
    	for (i=0;i<3;i++)
    	{
    		if (s[i]=='+')
    		c+=arr[i+1];
    		else
    		c*=arr[i+1];
		}
		if (c<mini)
		mini=c;
		if (s[0]=='+')
		a=arr[0]+arr[1];
		else
		a=arr[0]*arr[1];
		if (s[1]=='+')
		b=arr[2]+arr[3];
		else
		b=arr[2]*arr[3];
		d=0;
		if (s[2]=='+')
		d=a+b;
		else
		d=a*b;
		if (d<mini)
		mini=d;
	}while (next_permutation(arr,arr+4));
	cout << mini;
}