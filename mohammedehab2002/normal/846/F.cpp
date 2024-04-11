#include <iostream>
#include <vector>
using namespace std;
vector<int> q[1000005];
int arr[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	long long cur=0,ans=0;
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=n-1;i>=0;i--)
	{
	    if (!q[arr[i]].empty())
	    cur-=n-q[arr[i]].back();
	    q[arr[i]].push_back(i);
	    cur+=n-i;
	    ans+=cur;
	}
	double den=(double)n*n;
	printf("%.9lf",(double)(2*ans-n)/den);
}