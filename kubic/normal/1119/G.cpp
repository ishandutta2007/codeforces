#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define pb push_back
char *P1,*P2,buf[LIM];
int n,m,c,s,a[N],b[N];vector<int> vc[N];
struct Node {int x,w;bool operator < (Node t) const {return w==t.w?x<t.x:w<t.w;}};
set<Node> z;
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void print(int x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
bool cmp(Node x,Node y) {return x.x<y.x;}
int main()
{
	n=rd();m=rd();for(int i=1;i<=m;++i) a[i]=rd(),s+=a[i];c=(s-1)/n+1;a[1]+=n*c-s;
	print(c);putchar('\n');for(int i=1;i<=m;++i) z.insert((Node) {i,a[i]});
	for(int i=1;i<=m;++i)
	{
		Node t;
		while(1)
		{
			t=*--z.end();if(t.w<n) break;z.erase(t);
			for(int j=i;j<=m;++j) vc[j].pb(t.x);t.w-=n;--c;z.insert(t);
		}if(!c) continue;t=*z.begin();z.erase(t);vc[i].pb(t.x);b[i]=t.w;n-=t.w;
		for(int j=1;j<c;++j)
			t=*--z.end(),z.erase(t),vc[i].pb(t.x),t.w-=b[i],z.insert(t);
	}b[m]+=n;for(int i=1;i<=m;++i) print(b[i]),putchar(' ');putchar('\n');
	for(int i=0;i<vc[1].size();++i,putchar('\n')) for(int j=1;j<=m;++j)
		print(vc[j][i]),putchar(' ');return 0;
}