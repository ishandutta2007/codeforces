#include <iostream>
#include <deque>
using namespace std;
deque<int> p;
int cnt,arr[2000005];
long long cur=0,ans=(1LL<<60),idx=-1;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		if (i<a)
		{
			cnt++;
			arr[a-i-1]++;
		}
		p.push_back(a);
		cur+=abs(a-i);
	}
	for (int i=0;i<n;i++)
	{
		if (cur<ans)
		{
			ans=cur;
			idx=i;
		}
		cur-=cnt;
		cur+=n-cnt-1;
		int tmp=p.back();
		p.pop_back();
		cur-=n-tmp;
		cur+=tmp-1;
		cnt++;
		arr[i+tmp-1]++;
		cnt-=arr[i];
		p.push_front(tmp);
	}
	printf("%I64d %d",ans,idx);
}