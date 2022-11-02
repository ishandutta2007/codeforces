#include<bits/stdc++.h>
using namespace std;

int ans[40000010];
int n;

void prepare()
{
	for (int i=2;i<=(1<<25);i<<=1)
	{
		int x=i>>1;
		for (int j=x;j<i;j++)
			ans[j]=i-1;
		/*
		if (i==2)	continue;
		x=i-1;
		ans[i-1]=0;
		for (int j=1;j<x;j++)
			ans[i-1]=max(ans[i-1],__gcd(x^j,x&j));
		printf("ans[%d]=%d;\n",i-1,ans[i-1]);
		*/
	}
}
int main()
{
	prepare();
	ans[3]=1;
ans[7]=1;
ans[15]=5;
ans[31]=1;
ans[63]=21;
ans[127]=1;
ans[255]=85;
ans[511]=73;
ans[1023]=341;
ans[2047]=89;
ans[4095]=1365;
ans[8191]=1;
ans[16383]=5461;
ans[32767]=4681;
ans[65535]=21845;
ans[131071]=1;
ans[262143]=87381;
ans[524287]=1;
ans[1048575]=349525;
ans[2097151]=299593;
ans[4194303]=1398101;
ans[8388607]=178481;
ans[16777215]=5592405;
ans[33554431]=1082401;
	int te;
	scanf("%d",&te);
	for (int ca=1;ca<=te;ca++)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]);
	}
	return 0;
}