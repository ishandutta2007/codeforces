#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 1555;

int n,m;
int a[maxn][maxn],b[maxn][maxn];
int ida[maxn];
int ans[maxn],ansn,nowj;
inline bool cmpa(const int x,const int y)
{
	return a[x][nowj]<a[y][nowj];
}

int ok[maxn],cut[maxn];
int s[maxn][maxn],si[maxn];

queue<int>q;

int main()
{
	read(n); read(m);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		read(a[i][j]);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		read(b[i][j]);
	
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n-1;i++) if(b[i][j]>b[i+1][j])
			s[j][i]=1,si[j]++;
	}
	for(int j=0;j<m;j++) if(!si[j]) q.push(j);
	
	while(!q.empty())
	{
		int chose=q.front(); q.pop();
		ans[++ansn]=chose;
		for(int j=0;j<n-1;j++) if(!cut[j])
		{
			if(b[j][chose]!=b[j+1][chose]) 
			{
				cut[j]=1;
				for(int k=0;k<m;k++) if(s[k][j]==1)
				{
					s[k][j]=0;
					si[k]--;
					if(!si[k]) q.push(k);
				}
			}
		}
	}
	
	for(int i=0;i<n;i++) ida[i]=i;
	for(int i=ansn;i>=1;i--) 
	{
		nowj=ans[i];
		stable_sort(ida,ida+n,cmpa);
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(a[ida[i]][j]!=b[i][j])
	{
		puts("-1");
		return 0;
	}
	
	printf("%d\n",ansn);
	for(int i=ansn;i>=1;i--) printf("%d ",ans[i]+1);
	puts("");
	
	return 0;
}