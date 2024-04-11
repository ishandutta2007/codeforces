#include<iostream>
#include<cmath>
using namespace std;
int n,m,city[111111],tower[111111],ans,low,high,mid,dist;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>city[i];
	for (int i=1;i<=m;i++) cin>>tower[i];
	for (int i=1;i<=n;i++)
	{
		low=1;
		high=m;
		while(low+1<high)
		{
			mid=(low+high)/2;
			if (tower[mid]>city[i]) high=mid;
			else low=mid;
		}
		dist=min(abs(city[i]-tower[low]),abs(tower[high]-city[i]));
		ans=max(ans,dist);
	}
	cout<<ans<<endl;
	return 0;
}