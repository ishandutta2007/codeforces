#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n;
int a[N];
set<int> S;
inline void solve()
{
	int idx;
	set<int>::iterator it,jt;
	register int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	S.clear();
	S.insert(a[1]);it=S.begin();
	for(i=2;i<=n;i++)
		if(a[i]==a[i-1])
			continue;
		else if(a[i]>a[i-1])
		{
			jt=it;jt++;
			if(jt==S.end())
				S.insert(a[i]),it=S.find(a[i]);
			else if(*jt==a[i])
				it=jt;
			else if(*jt>a[i])
				S.insert(a[i]),it=S.find(a[i]);
			else
				return puts("NO"),void();
		}
		else
		{
			if(it==S.begin())
				S.insert(a[i]),it=S.find(a[i]);
			else
			{
				jt=it;jt--;
				if(*jt==a[i])
					it=jt;
				else if(*jt<a[i])
					S.insert(a[i]),it=S.find(a[i]);
				else
					return puts("NO"),void();
			}
		}
	puts("YES");
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}