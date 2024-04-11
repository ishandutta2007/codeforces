//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>59;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
mt19937 rnd(1919810);int n,h;pair<int,int>p[1<<18|1];
int main()
{
	read(h),n=(1<<h)-1;for(int i=1;i<=n;i++) p[i].second=i;
	for(int i=1,x,y,w,z;i<=420;i++)
	{
		x=rnd()%n+1,y=rnd()%n+1,z=rnd()%n+1;
		{while(x==y) y=y%n+1;}while(y==z||x==z) z=z%n+1;
		printf("? %d %d %d\n",x,y,z),fflush(stdout),read(w),p[w].first++;
	}
	sort(p+1,p+n+1,greater<pair<int,int> >());int x=p[1].second,y=p[2].second;
	for(int i=1,w;i<=n;i++) if(i!=x&&i!=y)
	{
		printf("? %d %d %d\n",x,y,i),fflush(stdout);
		read(w);if(w==i) return printf("! %d\n",i),0;
	}
	return 0;
}