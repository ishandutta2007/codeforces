#include<iostream>
#include<algorithm>
using namespace std;
int n,k,a[1111],cur,pos,ans;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	cur=k;
	pos=1;
	while(pos<=n)
	{
		while(pos<=n && cur*2>=a[pos]) 
		{
			cur=max(cur,a[pos]);
			pos++;
		}
		if (pos>n) break;
		ans++;
		cur*=2;
	}
	cout<<ans<<endl;
	return 0;
}