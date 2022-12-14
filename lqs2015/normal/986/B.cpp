#include<iostream>
#include<cstdio>
using namespace std;
long long n,bit[2222222],a[1111111],sz,ans;
void update(long long i)
{
	while(i<=sz)
	{
		bit[i]++;
		i+=i&(-i);
	}
}
long long query(long long i)
{
	long long res=0;
	while(i>=1)
	{
		res+=bit[i];
		i-=i&(-i);
	}
	return res;
}
int main()
{
	scanf("%I64d",&n);
	sz=1;
	while(sz<n) sz*=2;
	for (long long i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (long long i=n;i>=1;i--) 
	{
		ans+=query(a[i]);
		update(a[i]);
	}
	if (ans%2==(3*n)%2) printf("Petr\n");
	else printf("Um_nik\n");
	return 0;
}