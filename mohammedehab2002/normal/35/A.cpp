#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
	int pos[]={1,2,3},i,p,n1,n2;
	cin >> p;
	for (i=0;i<3;i++)
	{
		cin >> n1 >> n2;
		swap (pos[n1-1],pos[n2-1]);
	}
	for (i=0;i<3;i++)
	{
		if (pos[i]==p)
		cout << i+1;
	}
}