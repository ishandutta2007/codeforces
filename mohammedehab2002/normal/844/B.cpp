#include <iostream>
#include <set>
using namespace std;
int cnt[55][2],cnt2[55][2],arr[55][55];
long long pows[60];
int main()
{
	long long n,m;
	cin >> n >> m;
	for (int i=0;i<n;i++)
	{
		for (int x=0;x<m;x++)
		{
			cin >> arr[i][x];
			cnt[i][arr[i][x]]++;
			cnt2[x][arr[i][x]]++;
		}
	}
	pows[0]=1LL;
	for (int i=1;i<60;i++)
	pows[i]=2LL*pows[i-1];
	long long ans=0;
	for (int i=0;i<n;i++)
	ans+=pows[cnt[i][0]]+pows[cnt[i][1]]-2;
	for (int i=0;i<m;i++)
	ans+=pows[cnt2[i][0]]+pows[cnt2[i][1]]-2;
	cout << ans-n*m;
}