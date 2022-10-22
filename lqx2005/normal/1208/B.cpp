#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=3000;
int n;
int a[N+5],b[N+5],minlen;
bitset<N+5> s;
bool check(int l,int r)
{
	s.reset();
	for(int i=1;i<=n;i++)
	{
		if(l<=i&&i<=r) continue;
		if(s.test(a[i])) return false;
		s.set(a[i]);
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	minlen=n;
	for(int l=1,r=0;l<=n;l++)  
	{
		while(r<n&&!check(l,r)) r++;
		if(check(l,r)) minlen=min(minlen,r-l+1);
	}
	if(check(0,-1)) printf("0\n");
	else printf("%d\n",minlen);
	return 0;
}