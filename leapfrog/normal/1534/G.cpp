//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
struct node
{
	int x,y;inline node r() {return(node){y,x};}
	char operator<(node b) const {return x^b.x?x<b.x:y<b.y;}
}a[800005];int n;priority_queue<node>q1,q2;ll rs=0;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y);
	sort(a+1,a+n+1,[](node a,node b){return a.x+a.y<b.x+b.y;});
	q1.push(a[1]),q2.push(a[1].r());for(int i=2,v;i<=n;i++)
		if(q1.top().x>a[i].x)
		{
			node x=q1.top();q1.pop();rs+=(v=x.x-a[i].x);
			q1.push(a[i]),q1.push(a[i]),q2.push((node){a[i].y-v,a[i].x+v});
		}
		else if(q2.top().x>a[i].y)
		{
			node x=q2.top();q2.pop(),rs+=(v=x.x-a[i].y);
			q2.push(a[i].r()),q2.push(a[i].r()),q1.push((node){a[i].x-v,a[i].y+v});
		}else q1.push(a[i]),q2.push((node){a[i].y,a[i].x});
	return printf("%lld\n",rs),0;
}