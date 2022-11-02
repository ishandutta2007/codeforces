//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
char a[1000005],b[1000005];int T,n,k,t1[135],t2[135];
int main()
{
	for(read(T);T--;)
	{
		read(n),read(k),scanf("%s%s",a+1,b+1);int tag=1;
		memset(t1,0,sizeof(t1));for(int i=1;i<=n;i++) t1[a[i]-'a']++;
		memset(t2,0,sizeof(t2));for(int i=1;i<=n;i++) t2[b[i]-'a']++;
		for(int i=0;i<25&&tag;i++)
		{
			while(t1[i]>=k&&t1[i]!=t2[i]) t1[i]-=k,t1[i+1]+=k;
			if(t1[i]!=t2[i]) puts("No"),tag=0;
		}
		if(!tag);else if(t1[25]==t2[25]) puts("YES");else puts("NO");
	}
}