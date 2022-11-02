#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=500001;
int n,m,T; 
char a[4][N];
int num[4][2];

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

void print(int x,int y,int t)
{
	if (num[x][t]<num[y][t]) swap(x,y);
	//cout << x << " " << y << " " << t << endl;
	char tt=t+'0';
	int j=0;
	for (int i=1;i<=2*n;i++)
	{
		if (a[x][i]==tt)
		{
			while (j<2*n) 
			{
				++j;
				//cout << j << " " << a[y][j] << endl;
				if (a[y][j]!=tt) cout << a[y][j];
				else break;
			}
			cout << tt;
		}
		else cout << a[x][i];
	}
	while (j<2*n) 
	{
		++j;
		cout << a[y][j];
	}
} 

void work()
{
	n=read();
	for (int i=1;i<=2*n;i++) cin >> a[1][i];
	for (int i=1;i<=2*n;i++) cin >> a[2][i];
	for (int i=1;i<=2*n;i++) cin >> a[3][i];
	mem(num);
	for (int i=1;i<=3;i++)
	{
		for (int j=1;j<=2*n;j++)
		{
			if (a[i][j]=='0') num[i][0]++;
			else num[i][1]++;
		}
	}
	for (int i=1;i<=3;i++)
	{
		for (int j=i+1;j<=3;j++)
		{
			if (num[i][0]<=n&&num[j][0]<=n) 
			{
				print(i,j,1);
				return;
			}
			else if (num[i][1]<=n&&num[j][1]<=n) 
			{
				print(i,j,0);
				return;
			}
		}
	}
	return;
}

int main()
{
	T=read();
	while (T--)
	{
		work();
		puts("");
	}
	return 0;
}