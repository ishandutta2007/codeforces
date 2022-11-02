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

#define maxn 150010
int n,m,q;
int a[maxn];
set<int>	S;

int main()
{
	read(n);read(m);read(q);
	for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=q;i++)
	{
		int op,x;
		read(op),read(x);
		if (op==1)
		{
			S.insert(a[x]);
			if (S.size()>m)	S.erase(S.begin());
		}	else
		{
			int mjy=S.count(a[x]);
			if (mjy)	printf("YES\n");else printf("NO\n");
		}
	}
	return 0;
}