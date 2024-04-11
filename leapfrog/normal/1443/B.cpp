//
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
char c[100005];int a,b,Q,n;
int main()
{
	for(read(Q);Q--;)
	{
		read(a),read(b),scanf("%s",c+1),n=strlen(c+1);int res=0,i=1;
		while(c[i]=='0') i++;
		for(int tot=100000;i<=n;i++)
		{
			if(c[i]=='0') {tot++;continue;}else if(tot*b>=a) {tot=0;continue;}else tot=0;
			int j=i-1;while(j>=1&&c[j]=='0') c[j]='1',j--,res+=b;
		}
//		printf("%s\n",c+1);
		for(int i=1,fg=0;i<=n;i++) if(c[i]=='0') fg=0;else if(!fg) res+=a,fg++;
		printf("%d\n",res);
	}
	return 0;
}