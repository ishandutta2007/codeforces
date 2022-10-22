#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pb push_back
#define po pop_back
#define set(a,vl) memset(a,vl,sizeof(a))
int n,m,cnt,stL[N],stR[N];char a[N];
vector<int> vcLR,vcRL,vc[N];
void print(vector<int> vc)
{for(int i=0;i<vc.size();++i) printf("%d ",vc[i]);}
int main()
{
	scanf("%s",a+1);n=strlen(a+1); 
	for(int i=1;i<=n;++i) if(a[i]=='L') ++cnt;
	if(cnt*2<n) for(int i=1;i<=n;++i)
		a[i]=a[i]=='L'?'R':'L'; 
	for(int i=1,t;i<=n;++i) if(a[i]=='L')
	{
		if(stR[0]) t=stR[stR[0]--];else t=++m;
		vc[t].pb(i);stL[++stL[0]]=t;
	}
	else
	{
		if(stL[0]) t=stL[stL[0]--];else t=++m;
		vc[t].pb(i);stR[++stR[0]]=t;
	}printf("%d\n",m-1);set(stL,0);set(stR,0);
	for(int i=1,sz,t1,t2;i<=m;++i)
	{
		sz=vc[i].size();t1=vc[i][0];t2=vc[i][sz-1];
		if(a[t1]=='L' && a[t2]=='R')
			for(int j=0;j<sz;++j) vcLR.pb(vc[i][j]);
		if(a[t1]=='R' && a[t2]=='L')
			for(int j=0;j<sz;++j) vcRL.pb(vc[i][j]);
		if(a[t1]=='L' && a[t2]=='L') stL[++stL[0]]=i;
		if(a[t1]=='R' && a[t2]=='R') stR[++stR[0]]=i;
	}
	if(vcLR.size() && vcRL.size())
	{
		int tLR=vcLR[vcLR.size()-1],tRL=vcRL[vcRL.size()-1];
		if(tLR<tRL) vcLR.pb(tRL),vcRL.po();
		else vcRL.pb(tLR),vcLR.po();print(vcLR);print(vcRL);
		for(int i=1;i<=stL[0];++i)
			print(vc[stL[i]]),print(vc[stR[i]]); 
	}
	else if(vcLR.size())
	{
		print(vcLR);
		for(int i=1;i<=stL[0];++i)
			print(vc[stL[i]]),print(vc[stR[i]]);
	}
	else
	{
		for(int i=stL[0];i;--i)
			print(vc[stR[i]]),print(vc[stL[i]]);print(vcRL);
	}return 0;
}