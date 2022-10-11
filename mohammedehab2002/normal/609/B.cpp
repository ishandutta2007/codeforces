#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int cnt[m],arr[n];
	memset(cnt,-1,sizeof(cnt));
	for (int i=0;i<n;i++)
	{
		cin >> arr[i];
		arr[i]--;
		cnt[arr[i]]++;
	}
	long long ans=0;
	for (int i=0;i<n;i++)
	{
		ans+=n-i-cnt[arr[i]]-1;
		cnt[arr[i]]--;
	}
	cout << ans;
}