#include <bits/stdc++.h>
using namespace std;
#define N 100005
int T,n,m,c,mn,mx,a[N],ord[N],ans[N];
struct Node {int x,w;bool operator < (Node t) const {return w>t.w;}}; 
priority_queue<Node> q;
bool cmp(int x,int y) {return a[x]<a[y];}
void slv()
{
	scanf("%d %d %d",&n,&m,&c);
	for(int i=1;i<=n;++i) ord[i]=i,scanf("%d",&a[i]);
	sort(ord+1,ord+n+1,cmp);
	for(int i=1;i<=m;++i) q.push((Node) {i,0});
	for(int i=n;i;--i)
	{
		Node t=q.top();q.pop();t.w+=a[ord[i]];
		ans[ord[i]]=t.x;q.push(t);
	}mn=q.top().w;for(int i=1;i<m;++i) q.pop();
	mx=q.top().w;q.pop();
	if(mx-mn>c) {puts("NO");return;}puts("YES");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);puts("");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0; 
}