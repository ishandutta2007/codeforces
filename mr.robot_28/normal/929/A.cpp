#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
    int A[n];
    for(int i=0; i<n; i++)
    {
    	cin >> A[i];
	}
	int coun=0, h=A[0];
	for(int i=1; i<=n-1; i++)
	{
		if(A[i]-h>k)
		{
			cout << "-1";
			return 0;
		}
		if(A[i]-h<=k)
		{
		while(A[i]-h<=k)
		{
			i++;
			if(i==n)
			{
				break;
			}
		}
		i--;
		h=A[i];
		coun++;
	    }
	}
	cout << coun;
    return 0;
}