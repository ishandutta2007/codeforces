#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,a,tmp;
    cin >> n;
    for (i=0;i<n;i++)
    {
    	cin >> a;
    	while (a%3==0)
    	a/=3;
    	while (a%2==0)
    	a/=2;
    	if (i==0)
    	tmp=a;
    	if (tmp!=a)
    	{
    		cout << "No";
    		return 0;
		}
	}
	cout << "Yes";
}