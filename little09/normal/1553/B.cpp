#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=1001;
int n,m,T; 
char a[N],b[N];

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 
int lena,lenb;
bool check(int x,int y)
{
	int tot=x;
	for (int i=y;i<lenb;i++)
	{
		if (tot<0||b[i]!=a[tot]) return 0;
		tot--;
	}
	return 1;
}
void work()
{
	cin >> a >> b;
	lena=strlen(a),lenb=strlen(b);
	for (int i=0;i<lena;i++)
	{
		int tot=0;
		for (int j=i;j<lena;j++)
		{
			if (a[j]!=b[tot]) break;
			if (check(j-1,tot+1))
			{
				cout << "YES\n";
				return;
			}
			tot++;
		}
	}
	cout << "NO\n";
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
	}
	return 0;
}