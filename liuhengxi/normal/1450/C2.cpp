#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=305;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,c[3][3],d[2];
char s[N][N];
int main()
{
	read(t);
	while(t--)
	{
		int mx=0;
		read(n);
		F(i,0,n)scanf("%s",s[i]);
		c[0][0]=c[0][1]=c[0][2]=c[1][0]=c[1][1]=c[1][2]=c[2][0]=c[2][1]=c[2][2]=0;
		d[0]=d[1]=0;
		F(i,0,n)F(j,0,n)if(s[i][j]!='.')
		{
			++c[(i+j)%3][2];
			++c[(i+j)%3][s[i][j]=='X'];
		}
		if(c[1][2]>c[mx][2])mx=1;
		if(c[2][2]>c[mx][2])mx=2;
		for(int i=0,j=0;i<3;++i)if(i!=mx)
		{
			F(x,0,n)F(y,0,n)if((x+y)%3==i&&s[x][y]!='.')++d[j^(s[x][y]=='X')];
			++j;
		}
		for(int i=0,j=0;i<3;++i)if(i!=mx)
		{
			if(j==(d[0]<d[1])){F(x,0,n)F(y,0,n)if((x+y)%3==i&&s[x][y]!='.')s[x][y]='O';}
			else{F(x,0,n)F(y,0,n)if((x+y)%3==i&&s[x][y]!='.')s[x][y]='X';}
			++j;
		}
		F(i,0,n)puts(s[i]);
	}
	return 0;
}