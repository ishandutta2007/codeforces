#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=20;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int h,w,ans,x,y;
char s[N][N];
int main()
{
	read(h);read(w);F(i,0,h)gets(s[i]);
	if(s[0][0]=='*')++ans;
	while(true)
	{
		bool find=false;
		F(i,1,h+w)if(!find)F(j,0,i+1)if(s[x+j][y+i-j]=='*')
		{
			find=true;x+=j;y+=i-j;break;
		}
		if(!find)break;
		else ++ans;
	}
	printf("%d\n",ans);
	return 0;
}