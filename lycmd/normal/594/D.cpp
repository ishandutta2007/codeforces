#include<bits/stdc++.h>
using namespace std;
int const N=1000010,MOD=1000000007;
int n,q,a[N],s[N],tr[N],pr[N],pre[N],ans[N];
vector<int>v;
vector<pair<int,int> >p[N];
namespace fastio{
#define gc() (uu==vv&&(vv=(uu=cc)+fread(cc,1,1<<21,stdin),uu==vv)?EOF:*uu++)
#define pc(c) (*o++=(c))
	int const NN=23333333;
	char cc[NN],*uu=cc,*vv=cc,buf[NN],*p1=buf,*p2=buf,obuf[NN],*o=obuf;
	int read(){
		char c=gc();
		int x=0,flg=1;
		while(c<48||c>57){
			if(c==EOF)exit(0);
			flg=c=='-'?-flg:flg,c=gc();
		}
		while(c>47&&c<58)x=(x<<1)+(x<<3)+c-48,c=gc();
		return x*flg;
	}
	int gtc(){
		char c=gc();         
		while(c<=32)c=gc();
		return c;
	}
	void write(int x){
		if(x<0)pc('-'),x=-x;
		if(x>9)write(x/10);
		pc((x%10)|48);
	}
	void writeln(int x){
		write(x),pc(10);
	} 
	void flush(){
		fwrite(obuf,o-obuf,1,stdout);
	}
#undef gc
#undef pc
}
using namespace fastio;
int qpow(int x,int y){
	return y?1ll*qpow(1ll*x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
void add(int x,int y){
	for(;x<N;x+=x&-x)
		tr[x]=1ll*tr[x]*y%MOD;
}
int ask(int x){
	int res=1;
	for(;x;x&=x-1)
		res=1ll*res*tr[x]%MOD;
	return res;
}
signed main(){
	for(int i=1;i<N;i++)
		tr[i]=1;
	for(int i=2;i<N;i++)
		if(!pr[i])
			for(int j=i;j<N;j+=i)
				pr[j]=i;
	n=read(),s[0]=1;
	for(int i=1;i<=n;i++)
		a[i]=read(),s[i]=1ll*s[i-1]*a[i]%MOD;
	q=read();
	for(int i=1,l,r;i<=q;i++)
		l=read(),r=read(),p[r].push_back({l-1,i});
	for(int i=1;i<=n;i++){
		int x=a[i];
		v.clear();
		while(x>1)
			v.push_back(pr[x]),x/=pr[x];
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int j:v){
			add(i,1ll*(j-1)*qpow(j,MOD-2)%MOD);
			if(pre[j])
				add(pre[j],1ll*j*qpow(j-1,MOD-2)%MOD);
			pre[j]=i;
		}
		for(auto j:p[i])
			ans[j.second]=1ll*s[i]*qpow(s[j.first],MOD-2)%MOD
				*ask(i)%MOD*qpow(ask(j.first),MOD-2)%MOD;
	}
	for(int i=1;i<=q;i++)
		writeln(ans[i]);
	flush();
}