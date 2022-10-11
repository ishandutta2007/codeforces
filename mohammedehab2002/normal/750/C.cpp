#include <iostream>
#include <stdio.h>
using namespace std;
int n,cum,a,b,en=1000000000;
pair<int,int> arr[200005];
int im()
{
	int r=en;
	pair<int,int> l[2]={make_pair(1900,2000000000),make_pair(-1000000000,1899)};
	for (int i=0;i<n;i++)
	{
		if (r<l[arr[i].second].first || r>l[arr[i].second].second)
		return 1;
		r+=arr[i].first;
	}
	return 0;
}
int main()
{
    cin >> n;
    for (int i=0;i<n;i++)
    {
    	scanf("%d%d",&a,&b);
    	arr[i]=make_pair(a,b-1);
    	if (b==2)
    	en=min(en,1899-cum);
    	cum+=a;
	}
	if (en==1000000000)
	cout << "Infinity";
	else if (im())
	cout << "Impossible";
	else
	cout << en+cum;
}