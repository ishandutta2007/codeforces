#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
char s[maxn],s2[maxn];
bitset<maxn> bit[26],one,nnm;
int n,m;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	one.set();
	for (int i=0;i<n;i++)
	{
		bit[s[i]-'a'][i]=1;
	}
	scanf("%d",&m);
	while (m--)
	{
		int op;
		scanf("%d",&op);
		if (op==1)
		{
			int x;
			char c[10];
			scanf("%d%s",&x,c);
			x--;
			bit[s[x]-'a'][x]=0;
			s[x]=c[0];
			bit[s[x]-'a'][x]=1;
		}	else
		{
			int l,r;
			scanf("%d%d%s",&l,&r,&s2);
			int len=strlen(s2);
			l--;r--;
			nnm=(one>>(100009-(r-len+1)))&(one<<l);
			for (int i=0;i<len;i++)
				nnm&=bit[s2[i]-'a']>>i;
			printf("%d\n",nnm.count());
		}
	}
	return 0;
}