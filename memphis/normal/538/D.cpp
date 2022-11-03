#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define rev(it,v) for(vector<int>::iterator it=v.begin();it!=v.end();it++)
using namespace std;
#define N 200005
#define LL long long
#define E 1010

struct rzz{
	int x,y;
}qaq[N],rw233[N],ans[N];

int n,nowx,nowy,x,y,bo,rw233cnt,qaqcnt,tot,flag[E][E];
char Ans[E][E],a[E][E];

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%s",a[i]+1);
	rep(i,1,n)
		rep(j,1,n)
		{
			if(a[i][j]=='x')
				rw233[++rw233cnt]=(rzz){i,j};
			if(a[i][j]=='o')
				qaq[++qaqcnt]=(rzz){i,j};
		}
	for(int i=1;i<=rw233cnt;i++)
		if(!flag[rw233[i].x][rw233[i].y])
		{
			bo=0;
			for(int j=1;j<=qaqcnt;j++)
			{
				x=rw233[i].x-qaq[j].x;
				y=rw233[i].y-qaq[j].y;
				bo=1;
				for(int k=1;k<=qaqcnt;k++)
					if(k^j)
					{
						nowx=qaq[k].x+x;
						nowy=qaq[k].y+y;
						if(nowx<=0||nowx>n||nowy<=0||nowy>n)continue;
						if(a[nowx][nowy]=='.')
						{
							bo=0;
							break;
						}
					}
				if(bo)
				{
					ans[++tot]=(rzz){x,y};
					for(int k=1;k<=qaqcnt;k++)
					{
						nowx=qaq[k].x+x;
						nowy=qaq[k].y+y;
						if(nowx<=0||nowx>n||nowy<=0||nowy>n)continue;
						flag[nowx][nowy]=1;
					}
					break;
				}
			}
			if(!bo)return puts("NO"),0;
		}
	for(int i=1;i<=2*n-1;i++)
		for(int j=1;j<=2*n-1;j++)Ans[i][j]='.';
	for(int i=1;i<=tot;i++)Ans[n+ans[i].x][n+ans[i].y]='x';
	Ans[n][n]='o';
	puts("YES");
	for(int i=1;i<=2*n-1;i++)	{
		for(int j=1;j<=2*n-1;j++)putchar(Ans[i][j]);
		putchar('\n');
	}
}