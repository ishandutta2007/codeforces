#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,int> m[10010];
int a[200010];
queue<ll> q[10010];
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int n,i,flg=1;ll s=0;cin>>n;
		for (i=1;i<=n;i++)
		{
			cin>>a[i];s+=a[i];m[T][a[i]]++;
		}
		q[T].push(s);
		for (i=0;i<=3*n && !q[T].empty();i++)
		{
			ll u=q[T].front();q[T].pop();
			if (m[T][u]) {m[T][u]--;continue;}
			if (u<=1) {flg=0;break;}
			q[T].push(u/2);q[T].push(u-(u/2));
		}
		if (flg && q[T].empty()) puts("YES");else puts("NO");
	}
}