#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define LIM 1000005
#define pb push_back
#define po pop_back
#define gc getchar
char *P1,*P2,buf[LIM];int n,m,ans=2e9,mn[N],ps[N],id[N];vector<int> z1,z2;
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
void print(int x) {if(x<10) {putchar(x+48);return;}print(x/10);putchar(x%10+48);}
int qry(int x,int y)
{
	putchar('?');putchar(' ');print(x);putchar(' ');print(y);
	putchar('\n');fflush(stdout);return rd();
}
void SMAWK(vector<int> z1,vector<int> z2)
{
	int t,t1,t2;vector<int> z3;z3.clear();
	if(z1.size()==1)
	{for(auto i:z2) {t=qry(z1[0],i);if(t<mn[z1[0]]) mn[z1[0]]=t,ps[z1[0]]=i;}return;}
	if(z2.size()==1) {for(auto i:z1) mn[i]=qry(i,z2[0]),ps[i]=z2[0];return;}
	if(z1.size()<z2.size())
	{
		t1=0;t2=z2.size();z3.pb(z2[0]);
		for(int i=1;i<z2.size();++i)
		{
			while(~t1 && t2>z1.size() && qry(z1[t1],*--z3.end())>qry(z1[t1],z2[i]))
				z3.po(),--t1,--t2;
			if(t1+1<z1.size() || t2==z1.size()) z3.pb(z2[i]),++t1;else --t2;
		}SMAWK(z1,z3);return;
	}for(int i=1;i<z1.size();i+=2) z3.pb(z1[i]);SMAWK(z3,z2);
	for(int i=0;i<z2.size();++i) id[z2[i]]=i;
	for(int i=0,l,r;i<z1.size();i+=2)
	{
		l=0;r=z2.size()-1;if(i) l=id[ps[z1[i-1]]];if(i<z1.size()-1) r=id[ps[z1[i+1]]];
		for(int j=l;j<=r;++j)
		{t=qry(z1[i],z2[j]);if(t<mn[z1[i]]) mn[z1[i]]=t,ps[z1[i]]=z2[j];}
	}
}
int main()
{
	n=rd();m=rd();for(int i=1;i<=n;++i) z1.pb(i);for(int i=1;i<=m;++i) z2.pb(i);
	for(int i=1;i<=n;++i) mn[i]=2e9;SMAWK(z1,z2);
	for(int i=1;i<=n;++i) ans=min(ans,mn[i]);
	putchar('!');putchar(' ');print(ans);putchar('\n');fflush(stdout);return 0;
}