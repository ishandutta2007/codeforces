#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100005
const double eps=1e-8,inf=1e18;
struct node{int x, y;}e[maxn];
int n,st[maxn],top;
inline int sqr(int x){return x*x;}
bool cmp(node a, node b){return a.x==b.x?a.y<b.y:a.x<b.x;}
double getk(int x, int y)
{
	if (fabs(e[x].x-e[y].x)<eps) return inf;
	return (double)(e[x].y-e[y].y)/(double)(e[x].x-e[y].x);
}
signed main(){
	scanf("%I64d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d%I64d",&e[i].x,&e[i].y),e[i].y-=e[i].x*e[i].x;
    sort(e+1,e+n+1,cmp);
    for(int i=1;i<=n;i++){
    	while(top>=1&&e[st[top-1]].x==e[i].x)top--;
        while(top>=2&&getk(i,st[top-2])>=getk(st[top-1],st[top-2])){top--;}
        st[top++]=i;
    }
    printf("%I64d\n",top-1);
    return 0;
}