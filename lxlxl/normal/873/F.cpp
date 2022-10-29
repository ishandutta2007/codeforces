#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

const int maxn = 610000;

int n;
struct SAM
{
	int son[26],par,c,v;
}sam[maxn]; int root,las,tot;
void extend(const int w,const int v)
{
	int p=las,np; 
	sam[np=++tot].c=sam[p].c+1; sam[np].v=v;
	while(p&&!sam[p].son[w]) sam[p].son[w]=np,p=sam[p].par;
	if(!p) sam[np].par=root;
	else
	{
		int q=sam[p].son[w];
		if(sam[q].c==sam[p].c+1) sam[np].par=q;
		else
		{
			int nq=++tot; memcpy(sam[nq].son,sam[q].son,sizeof sam[q].son);
			sam[nq].par=sam[q].par;
			sam[nq].c=sam[p].c+1;
			sam[q].par=sam[np].par=nq;
		}
	}
	las=np;
}
inline bool cmp(const int x,const int y){return sam[x].c>sam[y].c;}
int t[maxn],tp;

char s1[maxn],s2[maxn];

int main()
{
	scanf("%d",&n);
	scanf("%s%s",s1,s2);
	root=las=tot=1;
	for(int i=0;i<n;i++) extend(s1[i]-'a',!(s2[i]-'0'));
	
	for(int i=1;i<=tot;i++) t[++tp]=i;
	sort(t+1,t+tp+1,cmp);
	for(int i=1;i<=tp;i++)
		sam[sam[t[i]].par].v+=sam[t[i]].v;
	
	ll ans=0;
	for(int i=1;i<=tot;i++) ans=max(ans,(ll)sam[i].c*sam[i].v);
	printf("%I64d\n",ans);
	
	return 0;
}