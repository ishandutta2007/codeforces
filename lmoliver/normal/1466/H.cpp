#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int MOD=1e9+7;
int add(int a,int b){return a+b<MOD?a+b:a+b-MOD;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return a>=b?a-b:a-b+MOD;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%MOD;}
void dmul(int &a,int b){a=mul(a,b);}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1)dmul(ans,a);
		b>>=1;
		dmul(a,a);
	}
	return ans;
}
int inv(int a){return ksm(a,MOD-2);}
struct Z{
	int v;
	Z(int v):v(v){}
}z(1);
Z operator*(Z a,Z b){return mul(a.v,b.v);}

const int N=44;
int fr[N];
int ifr[N];
int c(int n,int k){return k>=0&&k<=n?(z*fr[n]*ifr[k]*ifr[n-k]).v:0;}

typedef map<int,int> M;
ostream &operator<<(ostream &o,M mp){
	bool f=false;
	o<<"{";
	for(M::iterator it=mp.begin();it!=mp.end();it++){
		if(f)o<<",";
		else f=true;
		o<<it->first<<":"<<it->second;
	}
	return o<<"}";
}

map<M,int> ids;
int id(const M &mp){
	// for(auto p:mp)assert(p.second);
	int &res=ids[mp];
	if(!res)res=ids.size();
	return res;
}
const int S=1500;

int n;

int calc(int sz,int a){
	assert(a!=n);
	return ksm((z*fr[n]*fr[n-a-1]*ifr[n-a]).v,sz);
}

int dfs(const M &mp,int mpsz,int key=0,int acc=0){
	// cerr<<"dfs "<<mp<<" "<<key<<" "<<acc<<endl;
	static int mem[S][N][N];
	static bool ok[S][N][N];
	int id=::id(mp);
	int &ans=mem[id][key][acc];
	if(ok[id][key][acc])return ans;
	
	M::const_iterator it=mp.lower_bound(key);
	if(it==mp.end()){
		ans=acc?mul(mul(sub(0,1),dfs(mp,mpsz-acc)),calc(acc,mpsz-acc)):(int)mp.empty();
	}
	else{
		pair<int,int> p=*it;
		int kk=p.first;
		int x=p.second;
		// cerr<<mp<<" "<<key<<" "<<kk<<" "<<x<<endl;
		ans=0;
		F(i,0,x){
			M tmp=mp;
			tmp[kk]=x-i;
			if(!tmp[kk])tmp.erase(kk);
			int cxi=mul(i&1?sub(0,1):1,c(x,i));
			int chc=dfs(tmp,mpsz,kk+1,acc+i*kk);
			dadd(ans,mul(cxi,chc));
			// if(key==0&&acc==0)cerr<<mp<<" <- "<<tmp<<" v="<<cxi<<"*"<<chc<<"="<<mul(cxi,chc)<<endl;
		}
	}

	ok[id][key][acc]=true;
	// if(key==0&&acc==0){
	// 	cerr<<"dfs "<<mp<<" = "<<ans<<endl;
	// }
	return ans;
}

int p[N];
bool vis[N];
int main(){
	D(i,N){
		fr[i]=i?mul(fr[i-1],i):1;
		ifr[i]=inv(fr[i]);
	}

	// cerr<<c(5,2)<<endl;
	n=read();
	F(i,1,n)p[i]=read();
	map<int,int> qaq;
	F(i,1,n)if(!vis[i]){
		int c=0,x=i;
		while(!vis[x]){
			vis[x]=true;
			x=p[x];
			c++;
		}
		qaq[c]++;
		// cerr<<"sz="<<c<<endl;
	}
	// cerr<<"qaq="<<qaq<<endl;
	int ans=dfs(qaq,n);
	// cerr<<"ids.size()="<<ids.size()<<endl;
	printf("%d\n",ans);
	return 0;
}