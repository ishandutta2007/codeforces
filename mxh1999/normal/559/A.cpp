#include<bits/stdc++.h>
using namespace std;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

int a[7];
int ans=0;
int sum;
int main()
{
	for (int i=1;i<=6;i++)	read(a[i]);
	for (int i=1;i<=3;i++)	sum+=a[i];
	sum*=sum;
	sum-=a[1]*a[1];
	sum-=a[3]*a[3];
	sum-=a[5]*a[5];
	printf("%d\n",sum);
	return 0;
}