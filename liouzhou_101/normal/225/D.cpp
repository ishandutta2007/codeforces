#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int rev[]={1,0,3,2};

int n,m;
char s[20][20];
int limit[20][20];

int len;
int px[16],py[16];

int F[16][16][1<<14];
int head,tail,Qx[16*16*(1<<14)],Qy[16*16*(1<<14)],Q[16*16*(1<<14)];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	len=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			if ('0'<=s[i][j]&&s[i][j]<='9')
			{
				int x=s[i][j]-'0';
				px[x]=i;
				py[x]=j;
				len=max(len,x);
			}
			if (s[i][j]=='#')
				limit[i][j]=1;
		}
	int flag=0;
	for (int i=1;i<len-1;++i)
	{
		int vx=px[i+1]-px[i],vy=py[i+1]-py[i];
		for (int k=0;k<4;++k)
			if (dx[k]==vx&&dy[k]==vy)
				flag|=k<<((i-1)*2);
	}
	F[px[1]][py[1]][flag]=1;
	head=tail=1;
	Qx[1]=px[1];
	Qy[1]=py[1];
	Q[1]=flag;
}

void work()
{
	while (head<=tail)
	{
		int vx=Qx[head],vy=Qy[head],vflag=Q[head];
		int vdis=F[vx][vy][vflag];
		++head;
		for (int i=1,wx=vx,wy=vy;i<len-1;++i)
		{
			int k=(vflag>>((i-1)*2))&3;
			wx+=dx[k];
			wy+=dy[k];
			limit[wx][wy]=1;
		}
		for (int k=0;k<4;++k)
		{
			int wx=vx+dx[k],wy=vy+dy[k];
			if (wx>0&&wx<=n&&wy>0&&wy<=m)
				if (!limit[wx][wy])
				{
					int flag=((vflag<<2)&((1<<((len-2)*2))-1))|rev[k];
					if (!F[wx][wy][flag])
					{
						if (s[wx][wy]=='@')
						{
							cout<<vdis<<endl;
							return;
						}
						F[wx][wy][flag]=vdis+1;
						++tail;
						Qx[tail]=wx;
						Qy[tail]=wy;
						Q[tail]=flag;
					}
				}
		}
		for (int i=1,wx=vx,wy=vy;i<len-1;++i)
		{
			int k=(vflag>>((i-1)*2))&3;
			wx+=dx[k];
			wy+=dy[k];
			limit[wx][wy]=0;
		}
	}
	puts("-1");
}

int main()
{
	init();
	work();
	return 0;
}