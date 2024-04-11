#include <bits/stdc++.h>
using namespace std;
#define N 600005
#define LIM 1000005
#define ll __int128
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,tp,nxt[N],ps[N],vl[N];ll nw,ans;char a[N];struct Node {int x,w;}st[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
char rd1() {char c=0;while(!isalpha(c)) c=gc();return c;}
void print(ll x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
void upd(int x,int w) {for(;x<=n;x+=x&-x) vl[x]+=w;}
int qSm(int x) {int res=0;for(;x;x-=x&-x) res+=vl[x];return res;}
void ins(Node vl)
{
	while(tp && vl.w<st[tp].w)
		nw+=1ll*(qSm(st[tp].x)-qSm(st[tp-1].x))*(vl.w-st[tp].w),--tp;
	st[++tp]=vl;
}
int qry(int x)
{
	int l=1,r=tp,mid;
	while(l<=r) {mid=(l+r)/2;if(x<=st[mid].x) r=mid-1;else l=mid+1;}
	return st[l].w;
}
int main()
{
    n=rd();
    for(int i=1,vl,t;i<=n;++i)
    {
    	a[i]=(rd1()-'a'+ans)%26+'a';vl=rd()^(ans&(1<<30)-1);
		ins((Node) {i,vl});t=i-1;
    	if(i>1)
    	{
    		t=nxt[i-1];ps[i-1]=a[i]==a[t+1]?ps[t]:t;
			while(t && a[i]!=a[t+1]) t=nxt[t];
    		if(a[i]==a[t+1]) ++t;nxt[i]=t;
		}t=i-1;
		while(t) if(a[i]==a[t+1]) t=ps[t];
			else nw-=qry(i-t),upd(i-t,-1),t=nxt[t];
		if(a[1]==a[i]) nw+=vl,upd(i,1);ans+=nw;print(ans);putchar('\n');
	}return 0;
}