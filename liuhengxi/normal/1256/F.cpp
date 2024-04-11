#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int q,n,cnts[26],cntt[26],k;
char s[N],t[N];
int main()
{
	read(q);
	while(q--)
	{
		bool ans=true;
		read(n);
		scanf("%s%s",s,t);
		F(i,0,26)cnts[i]=cntt[i]=0;
		F(i,0,n)++cnts[s[i]-'a'],++cntt[t[i]-'a'];
		F(i,0,26)if(cnts[i]!=cntt[i])ans=false;
		if(ans==false)
		{
			puts("NO");
			continue;
		}
		ans=false;
		F(i,0,26)if(cnts[i]>1)ans=true;
		if(!ans)
		{
			k=0;
			F(i,1,n)F(j,0,n-i)if(s[j]>s[j+1])k^=1,s[j]^=s[j+1]^=s[j]^=s[j+1];
			F(i,1,n)F(j,0,n-i)if(t[j]>t[j+1])k^=1,t[j]^=t[j+1]^=t[j]^=t[j+1];
			if(k==0)ans=true;
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}