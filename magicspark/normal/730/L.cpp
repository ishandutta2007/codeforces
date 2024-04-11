/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,q,tot,cnt,pw[500005],val[500005];
string s;
char c[500005];
int l[500005],r[500005],bel[500005],prv[500005],suf[500005];
struct number{
	number(){}
	int l,r,val;
}num[500005];
vector<int>g[500005];
string read(){
	scanf("%s",c);
	return c;
}
void init(int x,int y){
	prv[x]=s[x]-'0';
	for(int i=x+1;i<=y;i++){
		prv[i]=(10ll*prv[i-1]+s[i]-'0')%mod;
	}
	suf[y]=s[y]-'0';
	for(int i=y-1;i>=x;i--){
		suf[i]=(1ll*pw[y-i]*(s[i]-'0')+suf[i+1])%mod;
	}
	num[bel[x]].val=prv[y];
	assert(prv[y]==suf[x]);
}
#define exp fwbefiuw
struct expr{
	vector<int>v;
	vector<int>range;
	vector<int>color;
	vector<int>pre;
	vector<int>mul,imul;
	vector<int>cnt;
	vector<int>mx;
	vector<int>unz;
	int result,id;
	//+inf:+ -inf:*
	exp(){}
	void calc(){
		int ans=0,cur=(v[0]==0?1:v[0]),pos=1,p=0;
		color.resize(v.size(),0);
		mul.resize(v.size(),0);
		imul.resize(v.size(),0);
		cnt.resize(v.size(),0);
		mx.resize(v.size(),0);
		mul[0]=(v[0]==0?1:v[0]);int cc=(v[0]==0);
		while(pos<v.size()){
			if(v[pos]==-inf){
				color[pos+1]=p;
				if(v[pos+1]!=0)cur=1ll*cur*v[pos+1]%mod;
				else cc++;
				mul[pos+1]=cur;cnt[pos+1]=cc;
			}else{
				mx[p]=cc;p++;color[pos+1]=p;
				pre.push_back(cc?0:cur);
				unz.push_back(cur);
				ans=(ans+(cc?0:cur))%mod;
				if(v[pos+1]!=0){
					cur=v[pos+1];cc=0;
				}else{
					cur=1;cc=1;
				}
				mul[pos+1]=cur;
				cnt[pos+1]=cc;
			}
			pos+=2;
		}
		ans=(ans+(cc?0:cur))%mod;pre.push_back(cc?0:cur);unz.push_back(cur);
		for(int i=0;i<v.size();i+=2)imul[i]=modpow(mul[i],mod-2);
		for(int i=1;i<pre.size();i++)pre[i]=(pre[i]+pre[i-1])%mod;
		result=ans;
	}
	int get_range(int x){
		if(x>inf)return x-inf;
		if(x>0)return l[x];
		else return num[-x].l;
	}
	void show(){
		cerr<<"show"<<endl; 
		for(auto t:v){
			if(t==inf)cerr<<'+';
			else if(t==-inf)cerr<<'*';
			else cerr<<t;
			cerr<<" ";
		}
		cerr<<endl;
	}
	int get(int l,int r){
		if(l==::l[id]&&r==::r[id]){
			return result;
		}
		if(bel[l]==bel[r]&&bel[l]!=0){
			return (prv[r]-1ll*prv[l-1]*pw[r-l+1]%mod+mod)%mod;
		}
		int L=0,R=v.size();
		while(R-L>1){
			int mid=(L+R)/2;
			if(get_range(range[mid])>l)R=mid;
			else L=mid;
		}
		if(::l[id]==l)return -1;
		if(range[L]<inf&&range[L]>0&&(l>::l[range[L]]||r<::r[range[L]]))return -1;
		int idl=L;
		L=0;R=v.size();
		while(R-L>1){
			int mid=(L+R)/2;
			if(get_range(range[mid])>r)R=mid;
			else L=mid;
		}
		if(::r[id]==r)return -1;
		if(range[L]<inf&&range[L]>0&&(l>::l[range[L]]||r<::r[range[L]]))return -1;
		int idr=L;
		if(range[idl]>=inf||range[idr]>=inf)return -1;
		if(color[idl]==color[idr]){
			int temp=1ll*mul[idr-2]*imul[idl]%mod;if(cnt[idr-2]>cnt[idl])temp=0;
			temp=1ll*temp*(range[idr]>0?v[idr]:prv[r])%mod*(range[idl]>0?v[idl]:suf[l])%mod;
			return temp;
		}else{
			int sum=(pre[color[idr]-1]-pre[color[idl]]+mod)%mod;
			int addl;
			if(mx[color[idl]]>cnt[idl])addl=0;
			else addl=1ll*unz[color[idl]]*imul[idl]%mod*(range[idl]>0?v[idl]:suf[l])%mod;
			int addr=1ll*(v[idr-1]==inf?1:(cnt[idr-2]?0:mul[idr-2]))*(range[idr]>0?v[idr]:prv[r])%mod;
			return (1ll*sum+addl+addr)%mod;
		}
	}
}exp[500005];
int go(int x){
//	cerr<<x<<" "<<tot+1<<endl;
	int cur=++tot;l[tot]=x-1;exp[tot].id=tot;
	while(1){
		if(s[x]=='('){
			int to=go(x+1);
			g[cur].push_back(to);
			x=r[to]+1;
			exp[cur].v.push_back(exp[to].result);
			exp[cur].range.push_back(to);
		}else if(s[x]<='9'&&s[x]>='0'){
			int y=x;
			while(s[y]<='9'&&s[y]>='0')y++;
			num[++cnt].l=x;num[cnt].r=y-1;
			for(int i=x;i<y;i++)bel[i]=cnt;
			g[cur].push_back(-cnt);init(x,y-1);
			exp[cur].v.push_back(num[cnt].val);
			exp[cur].range.push_back(-cnt);
			x=y;
		}
		if(x>n||s[x]==')'){
			x++;r[cur]=x-1;exp[cur].calc();return cur;
		}
		if(s[x]=='+'){
			exp[cur].v.push_back(inf);
			exp[cur].range.push_back(inf+x);
			x++;
		}else{
			exp[cur].v.push_back(-inf);
			exp[cur].range.push_back(inf+x);
			x++;
		}
	}
}
int ans[500005];
vector<pair<int,int> >rr[500005];
vector<pair<int,int> >qr[500005];
struct SGT{
	#define SIZE 524288
	int f[SIZE<<1];
	SGT(){memset(f,0,sizeof f);}
	void update(int x,int v){
		x+=SIZE;f[x]=v;
		while(x!=1){
			x>>=1;
			f[x]=max(f[x<<1],f[x<<1|1]);
		}
	}
	int ask(int l,int r,int k,int ql,int qr){
		if(qr<l||r<ql)return -inf;
		if(ql<=l&&r<=qr){
			return f[k];
		}
		int vl=ask(l,(l+r)/2,k<<1,ql,qr);
		int vr=ask((l+r)/2+1,r,k<<1|1,ql,qr);
		return max(vl,vr);
	}
}T;
void print(int x){
	cerr<<"show: "<<x<<endl;
	for(auto t:exp[x].v){
		if(t==inf)cerr<<'+';
		else if(t==-inf)cerr<<'*';
		else cerr<<t;
		cerr<<" ";
	}
	cerr<<endl;
}
int main(){
	pw[0]=1;
	for(int i=1;i<=500000;i++)pw[i]=10ll*pw[i-1]%mod;
	s=" "+read();n=s.size()-1;
	scanf("%d",&q);go(1);
	for(int i=1;i<=tot;i++)rr[r[i]].push_back(make_pair(l[i],i));
	for(int i=1;i<=n;i++)sort(rr[i].begin(),rr[i].end());
	for(int i=1;i<=q;i++){
		int a,b;scanf("%d%d",&a,&b);
		if(i==687)cerr<<a<<" "<<b<<endl;
		qr[b].push_back(make_pair(a,i));
	}
	for(int i=n+1;i>=1;i--){
		for(auto p:rr[i]){
			T.update(p.first,1e9-i);
		}
		for(auto p:qr[i]){
			int cur=1e9-T.ask(0,SIZE-1,1,0,p.first);
			auto itr=lower_bound(rr[cur].begin(),rr[cur].end(),make_pair(i,inf));
			itr--;ans[p.second]=exp[itr->second].get(p.first,i);
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}