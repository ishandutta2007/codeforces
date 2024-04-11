#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];
int n,m,cnt;bool vs[N];vector<int> e[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
void print(int x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
int main()
{
	n=rd();m=rd();for(int i=1;i<=n;++i) vs[i]=1;
	for(int i=1,u,v;i<=m;++i) u=rd(),v=rd(),e[u].pb(v);
	for(int i=1;i<=n;++i) if(vs[i]) for(auto j:e[i]) if(i<j) vs[j]=0;
	for(int i=n;i;--i) if(vs[i]) for(auto j:e[i]) if(i>j) vs[j]=0;
	for(int i=1;i<=n;++i) if(vs[i]) ++cnt;print(cnt);puts("");
	for(int i=1;i<=n;++i) if(vs[i]) print(i),putchar(' ');return 0;
}