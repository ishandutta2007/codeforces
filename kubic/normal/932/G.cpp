#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define MOD 1000000007
int n;char a[N];struct Point {int len,link,d,nxt,w,ch[26];};
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
struct PalindromeAutomaton
{
	int n,nw,cntP,a[N],dp[N];Point pt[N];
	PalindromeAutomaton()
	{cntP=dp[0]=1;a[0]=pt[1].len=pt[0].d=pt[1].d=-1;pt[0].link=1;}
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
			else pt[cntP].nxt=pt[pt[cntP].link].nxt;
		}nw=pt[nw].ch[vl];
		for(int i=nw,t;i>1;i=pt[i].nxt)
		{
			t=n-pt[pt[i].nxt].len-pt[i].d;pt[i].w=t&1?0:dp[t];
			if(pt[i].d==pt[pt[i].link].d) W(pt[i].w,pt[pt[i].link].w);
			W(dp[n],pt[i].w);
		}
	}
}PAM;
int main()
{
	scanf("%s",a+1);n=strlen(a+1);
	for(int i=1;i<=n/2;++i) PAM.ext(a[i]-'a'),PAM.ext(a[n-i+1]-'a');
	printf("%d\n",PAM.dp[n]);return 0;
}