#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=510;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m;
char s[N][N];
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(m);
		F(i,0,n)scanf("%s",s[i]),s[i][m]='\0';
		if(n%3==1)
		{
			F(i,0,n/3)
			{
				if(s[3*i+1][1]=='X'||s[3*i+2][1]=='X')s[3*i+1][1]='X',s[3*i+2][1]='X';
				else s[3*i+1][0]='X',s[3*i+2][0]='X';
			}
			F(i,0,n/3+1)F(j,0,m)s[3*i][j]='X';
		}
		else
		{
			
			F(i,0,(n+1)/3-1)
			{
				if(s[3*i+2][1]=='X'||s[3*i+3][1]=='X')s[3*i+2][1]='X',s[3*i+3][1]='X';
				else s[3*i+2][0]='X',s[3*i+3][0]='X';
			}
			F(i,0,(n+1)/3)F(j,0,m)s[3*i+1][j]='X';
		}
		F(i,0,n)puts(s[i]);
	}
	return 0;
}