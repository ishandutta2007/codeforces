#include <bits/stdc++.h>
using namespace std;
#define N 1000005
const int INF=1e9;
int n,dp[N],pr[N];char a1[N],a2[N];
struct Point {int len,link,d,nxt,w,ch[26];};
void W(int &x,int y) {if(~y && (x==-1 || dp[x]>dp[y])) x=y;}
struct PalindromeAutomaton
{
	int n,nw,cntP,a[N];Point pt[N];
	PalindromeAutomaton()
	{cntP=1;a[0]=pt[1].len=pt[0].d=pt[1].d=pt[0].w=pt[1].w=-1;pt[0].link=1;}
	int find(int p) {while(a[n]!=a[n-pt[p].len-1]) p=pt[p].link;return p;}
	void ext(int vl)
	{
		a[++n]=vl;nw=find(nw);
		if(!pt[nw].ch[vl])
		{
			pt[++cntP].link=pt[find(pt[nw].link)].ch[vl];
			pt[nw].ch[vl]=cntP;pt[cntP].len=pt[nw].len+2;
			pt[cntP].d=pt[cntP].len-pt[pt[cntP].link].len;
			if(pt[cntP].d!=pt[pt[cntP].link].d) pt[cntP].nxt=pt[cntP].link;
			else pt[cntP].nxt=pt[pt[cntP].link].nxt;pt[cntP].w=-1;
		}nw=pt[nw].ch[vl];pr[n]=-1;
		for(int i=nw,t;i>1;i=pt[i].nxt)
		{
			t=n-pt[pt[i].nxt].len-pt[i].d;pt[i].w=t&1?-1:t;
			if(pt[i].d==pt[pt[i].link].d) W(pt[i].w,pt[pt[i].link].w);
			W(pr[n],pt[i].w);
		}dp[n]=~pr[n]?dp[pr[n]]+1:INF;
		if(a[n]==a[n-1] && dp[n]>dp[n-2]) dp[n]=dp[n-2],pr[n]=n-2;
	}
}PAM;
int main()
{
	scanf("%s %s",a1+1,a2+1);n=strlen(a1+1);
	for(int i=1;i<=n;++i) PAM.ext(a1[i]-'a'),PAM.ext(a2[i]-'a');
	if(dp[n*2]>=INF) {printf("-1\n");return 0;}printf("%d\n",dp[n*2]);
	for(int i=n*2;i;i=pr[i]) if(pr[i]<i-2)
		printf("%d %d\n",pr[i]/2+1,i/2);return 0;
}