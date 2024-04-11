#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
pair <int,int> a[5];
int x1,x2,x3,Y1,y2,y3;
inline int cal(int x)
{
	int b[5]={0,x1,x2-x,x3-x};
	sort(b,b+4);
	int rtn=b[3]+b[2]-b[0]-b[1];
	b[1]=Y1-x,b[2]=y2-x,b[3]=y3,b[0]=0;
	sort(b,b+4);
	return rtn+b[3]+b[2]-b[0]-b[1];
}
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		for(int i=0;i<4;i++)
			cin >> a[i].first >> a[i].second;
		sort(a,a+4);
		int ans=1e18;
		do
		{
			x1=a[1].first-a[0].first;
			Y1=a[1].second-a[0].second;
			x2=a[2].first-a[0].first;
			y2=a[2].second-a[0].second;
			x3=a[3].first-a[0].first;
			y3=a[3].second-a[0].second;
			int l=0,r=1e9;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(cal(mid)>cal(mid-1)) ans=min(ans,cal(mid-1)),r=mid-2;
				else ans=min(ans,cal(mid)),l=mid+1;
			}
		}
		while(next_permutation(a,a+4));
		cout << ans << "\n";
	}
	return 0;
}