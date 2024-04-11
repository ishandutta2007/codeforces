#include <iostream>
#include <algorithm>
using namespace std;
int arr[3];
int main()
{
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr,arr+3);
	do {
		bool b=1;
		for (int i=4;i<10000000;i++)
		{
			if (!((i-1)%arr[0]==0 || (i-2)%arr[1]==0 || (i-3)%arr[2]==0))
			b=0;
		}
		if (b)
		{
			printf("YES");
			return 0;
		}
	} while(next_permutation(arr,arr+3));
	printf("NO");
}