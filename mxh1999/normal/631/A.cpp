#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

int n;
int a[1010],b[1010];
int main()
{
	read(n);
	for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=n;i++)	read(b[i]);
	int q=a[1],q2=b[1];
	for (int i=2;i<=n;i++)	q|=a[i],q2|=b[i];
	printf("%d\n",q+q2);
	return 0;
}