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

int n,a,b;

int main()
{
	read(n),read(a),read(b);
	a+=b;
	while (a<=0)	a+=n;
	while (a>n)	a-=n;
	printf("%d\n",a);
	return 0;
}