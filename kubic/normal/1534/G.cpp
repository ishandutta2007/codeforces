#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define ll long long
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,z[N];ll ans;struct Point {int x,y;}a[N];
priority_queue<int> q1;priority_queue<int,vector<int>,greater<int>> q2;
bool cmp(Point x,Point y) {return x.x+x.y<y.x+y.y;}
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
int main()
{
	n=rd();for(int i=1;i<=n;++i) a[i].x=rd(),a[i].y=rd();
	sort(a+1,a+n+1,cmp);q1.push(0);
	for(int i=1,x,d,t;i<=n;++i)
	{
		x=a[i].x;d=x+a[i].y;ans+=x;t=q1.top();
		if(x<=t) q1.push(x),q1.push(x),q2.push(q1.top()-d),q1.pop();
		else q2.push(x-d),q2.push(x-d),q1.push(q2.top()+d),q2.pop();
	}while(!q1.empty()) z[++z[0]]=q1.top(),q1.pop();
	for(int i=1;i<z[0];++i) ans-=1ll*(z[i]-z[i+1])*i;
	printf("%lld\n",ans);return 0;
}