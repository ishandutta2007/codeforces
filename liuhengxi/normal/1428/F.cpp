#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],start[N],length[N],top;
long long now,ans;
char s[N+1];
int main()
{
	read(n);
	scanf("%s",s);
	F(i,0,n)a[i]=s[i]-'0';
	F(i,0,n)
	{
		if(a[i])
		{
			if(top&&start[top-1]+length[top-1]==i)
			{
				++length[top-1];
				while(top>1&&length[top-1]>length[top-2])
				{
					start[top-2]=start[top-1];
					length[top-2]=length[top-1];
					--top;
				}
			}
			else start[top]=i,length[top]=1,++top;
			if(top>1)now+=i-start[top-2]-length[top-2]+length[top-1];
			else now+=i+1;
		}
		ans+=now;
	}
	printf("%lld\n",ans);
	return 0;
}