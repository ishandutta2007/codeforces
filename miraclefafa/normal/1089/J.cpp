#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n;
set<ll> s;
string vs[3300]; int vn=0;
char sp[3300]; int sn;
int su[3300],ml[3300][3300],ty[3300][3300];
pii hz[3300];
bool gg[3300];
bool ad[3300][3300],ag[3300][3300];
bool go[3300][3300];
ll hsh(const string& w)
{
	ll t=3;
	for(auto c:w)
		t=t*1233+c;
	return t;
}
bool good(char c)
{
	return isdigit(c)||isupper(c)
		||islower(c)||c=='_'||c=='$';
}
int safe(string& t)
{
	if(t.size()<=20&&s.count(hsh(t)))
		return 1;
	bool od=1,og=1;
	for(auto c:t)
	{
		od&=isdigit(c),og&=good(c);
		if(od||og);else return 0;
	}
	if(od) return 2;
	if(!isdigit(t[0])&&og) return 3;
	return 0;
}
int P=1,Q=26,C=-1;
string gnxt()
{
	++C;
	if(C==Q)
		++P,C=0,Q*=26;
	string s=""; int w=C;
	for(int j=0;j<P;++j)
		s.pb(w%26+'a'),w/=26;
	reverse(s.begin(),s.end());
	return s;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		string t; cin>>t;
		s.insert(hsh(t));
	}
	string w,u;
	int m;
	cin>>m;
	while(getline(cin,w))
	{
		int s=0;
		while(s<w.size()&&w[s]!='#') ++s;
		w.resize(s);
		u=u+" "+w;
	}
	for(int i=0;i<u.size();++i)
	{
		if(u[i]==' ') continue;
		string w=""; int ml=0;
		for(int j=i;j<u.size();++j)
		{
			w.pb(u[j]);
			if(safe(w)) ml=max(ml,int(w.size()));
		}
		vs[++vn]=u.substr(i,ml); i+=ml-1;
	}
	map<string,string> yy;
	for(int i=1;i<=vn;++i)
	{
		if(safe(vs[i])!=3) continue;
		if(yy.count(vs[i]))
		{
			vs[i]=yy[vs[i]];
			continue;
		}
		string w=vs[i],g;
		while(s.count(hsh(g=gnxt())));
		yy[vs[i]]=g; vs[i]=g;
	}
	for(int i=1;i<=vn;++i)
	{
		for(auto t:vs[i]) sp[++sn]=t;
		su[i]=sn;
		//i: [su[i-1]+1,su[i]]
	}
	for(int i=1;i<=sn+1;++i)
		ad[i][i-1]=ag[i][i-1]=1;
	for(int i=1;i<=sn;++i)
		for(int j=i;j<=sn;++j)
			ad[i][j]=ad[i][j-1]&isdigit(sp[j]),
			ag[i][j]=ag[i][j-1]&good(sp[j]);
	for(int i=1;i<=sn;++i)
	{
		ll t=3;
		for(int j=i;j<=sn;++j)
		{
			t=t*1233+sp[j];
			if(j-i+1<=21&&s.count(t)) ty[i][j]=1;
			else if(ad[i][j]) ty[i][j]=2;
			else if(ag[i][j]&&!isdigit(sp[i])) ty[i][j]=3;
		}
	}
	for(int i=1;i<=sn;++i)
		for(int j=i;j<=sn;++j)
			ml[i][j]=max(ml[i][j-1],(ty[i][j])?(j-i+1):0);
	for(int i=1;i<=vn+1;++i) go[i][i-1]=1;
	for(int j=1;j<=vn;++j)
		for(int i=j;i>=1;--i)
			go[i][j]=go[i+1][j]&&(ml[su[i-1]+1][su[j]]==(int)vs[i].size());
	hz[vn+1]=pii(0,0);
	for(int i=vn;i>=1;--i)
	{
		hz[i]=pii(1e9,0);
		for(int j=i;j<=vn;++j)
			if(go[i][j]) hz[i]=min(hz[i],pii(hz[j+1].fi+1,j));
	}
	int ww=1;
	while(ww<=vn)
	{
		int g=hz[ww].se;
		gg[g]=1; ww=g+1;
	}
	gg[vn]=0;
	for(int i=1;i<=vn;++i)
	{
		printf("%s",vs[i].c_str());
		if(gg[i]) putchar(' ');
	}
	puts("");
}