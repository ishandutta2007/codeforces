#include<bits/stdc++.h>
using namespace std;
const long long d=1e17;
long long A,l,r,fuck;
long long mul(long long a,int b)
{
	long long res=0,p=a;
	for (int i=b;i;i>>=1)
	{
		if (i&1) 
		{
			res=(res+p)%A;
		}
		p=(p+p)%A;
	}
	return res;
}
int main()
{
	scanf("%lld",&A);
	fuck=mul(d,810);
	l=A-fuck;r=A-fuck+999999999999999999ll;
	if (!l) l++;
	printf("%lld %lld\n",l,r);
	return 0;
}