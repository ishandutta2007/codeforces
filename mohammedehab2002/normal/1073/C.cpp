#include <iostream>
using namespace std;
int dx[200005],dy[200005];
int main()
{
	int n,x,y;
	string s;
	cin >> n >> s >> x >> y;
	if (n<abs(x)+abs(y) || n%2!=((x+y)%2+2)%2)
	{
		cout << -1;
		return 0;
	}
	for (int i=0;i<n;i++)
	{
		dx[i+1]=dx[i];
		dy[i+1]=dy[i];
		if (s[i]=='U')
		dy[i+1]++;
		else if (s[i]=='D')
		dy[i+1]--;
		else if (s[i]=='L')
		dx[i+1]--;
		else
		dx[i+1]++;
	}
	int ans=(1<<30);
	for (int i=0;i<=n;i++)
	{
		int st=i+1,en=n+2;
		while (st!=en)
		{
			int mid=(st+en)/2;
			int curx=dx[i]+dx[n]-dx[mid-1],cury=dy[i]+dy[n]-dy[mid-1];
			if (abs(x-curx)+abs(y-cury)<=mid-i-1)
			en=mid;
			else
			st=mid+1;
		}
		if (st!=n+2)
		ans=min(ans,st-i-1);
	}
	cout << ans;
}