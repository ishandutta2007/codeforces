#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1e9+7;
const int N=100100;
const int M=100100;
int u[M],v[M],w[M];
bool tr[N];

const int W=32;
const int L=5;
struct S{
	int a[L];
	bool z;
	S():a{0},z(false){}
	S(int code){
		if(code==0){
			z=true;
		}
		else{
			z=false;
			code--;
			a[0]=code&1;
			code>>=1;
			a[1]=code&3;
			code>>=2;
			a[2]=code&7;
			code>>=3;
			a[3]=code&15;
			code>>=4;
			a[4]=code&31;
		}
	}
	void add(int x){
		if(z)return;
		for(int i=L-1;i>=0;i--){
			if((x>>i)&1){
				if(a[i]==0){
					a[i]=x;
					return;
				}
				else{
					x^=a[i];
				}
			}
		}
		z=true;
	}
	int format(){
		if(z)return 0;
		for(int i=0;i<L;i++){
			if(a[i]!=0){
				for(int j=i+1;j<L;j++){
					if((a[j]>>i)&1){
						a[j]^=a[i];
					}
				}
			}
		}
		return (a[0]|(a[1]<<1)|(a[2]<<3)|(a[3]<<6)|(a[4]<<10))+1;
	}
	void mg(const S &o){
		if(o.z){
			z=true;
		}
		else{
			for(int i=0;i<L;i++){
				if(o.a[i]){
					add(o.a[i]);
				}
			}
		}
	}
};

struct UFS{
	int fa[N];
	UFS(){
		for(int i=0;i<N;i++)fa[i]=i;
	}
	int find(int x){
		return fa[x]==x?x:(fa[x]=find(fa[x]));
	}
	bool mg(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y)return false;
		fa[x]=y;
		return true;
	}
};

typedef vector<int> VI;
VI es[N];
UFS ufs;
UFS qaq;
S mp[N];
S mp2[N];
unordered_map<int,int> cnt;
int xr[N];

void dfs(int x,int fa=-1){
	// cerr<<"dfs "<<x<<" "<<xr[x]<<endl;
	for(int e:es[x]){
		int y=u[e]^v[e]^x;
		if(y!=fa){
			xr[y]=xr[x]^w[e];
			dfs(y,x);
		}
	}
}

int mem[2][N];
int *dp[2]={mem[0],mem[1]};
vector<int> s;
vector<int> s2;
bool has[N];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(u[i]!=1&&v[i]!=1){
			qaq.mg(u[i],v[i]);
			if(ufs.mg(u[i],v[i])){
				es[u[i]].push_back(i);
				es[v[i]].push_back(i);
				tr[i]=true;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(!tr[i]&&ufs.mg(u[i],v[i])){
			es[u[i]].push_back(i);
			es[v[i]].push_back(i);
			tr[i]=true;
		}
	}
	// for(int i=0;i<m;i++){
	// 	if(tr[i]){
	// 		cerr<<u[i]<<" "<<v[i]<<endl;
	// 	}
	// }
	dfs(1);
	for(int i=0;i<m;i++){
		if(!tr[i]&&u[i]!=1&&v[i]!=1){
			// cerr<<u[i]<<" "<<v[i]<<" "<<qaq.find(u[i])<<" add "<<(xr[u[i]]^xr[v[i]]^w[i])<<endl;
			mp[qaq.find(u[i])].add(xr[u[i]]^xr[v[i]]^w[i]);
			// cerr<<boolalpha<<mp[qaq.find(u[i])].z<<endl;
		}
	}
	for(int i=0;i<m;i++){
		if(u[i]==1||v[i]==1){
			int y=1^u[i]^v[i];
			int x=qaq.find(y);
			// cerr<<"qaq "<<y<<" "<<x<<endl;
			cnt[x]++;
			if(!tr[i]){
				S s=mp[x];
				s.add(xr[u[i]]^xr[v[i]]^w[i]);
				mp2[x]=s;
			}
		}
	}
	dp[0][1]=1;
	has[1]=true;
	s.push_back(1);
	for(pair<int,int> p:cnt){
		for(int code:s){
			dp[1][code]=dp[0][code];
		}
		int c=p.second;
		// cerr<<c<<endl;
		for(int code:s){
			LL w=dp[0][code];
			// cerr<<"+ "<<code<<" "<<w<<endl;
			if(c==1){
				S x(code);
				// cerr<<"x = "<<x.format()<<endl;
				x.mg(mp[p.first]);
				// cerr<<"mg "<<mp[p.first].format()<<endl;
				int xc=x.format();
				// cerr<<"x = "<<xc<<endl;
				if(!has[xc]){
					has[xc]=true;
					s2.push_back(xc);
				}
				(dp[1][xc]+=w)%=MOD;
			}
			else{ // c==2
				S x(code);
				S y=x;
				x.mg(mp[p.first]);
				int xc=x.format();
				if(!has[xc]){
					has[xc]=true;
					s2.push_back(xc);
				}
				(dp[1][xc]+=w*2%MOD)%=MOD;
				y.mg(mp2[p.first]);
				int xc2=y.format();
				if(!has[xc2]){
					has[xc2]=true;
					s2.push_back(xc2);
				}
				(dp[1][xc2]+=w)%=MOD;
			}
		}
		swap(dp[0],dp[1]);
		for(int code:s2){
			s.push_back(code);
		}
		s2.clear();
	}
	int ans=0;
	for(int i=1;i<N;i++){
		// cerr<<p.first<<" "<<p.second<<endl;
		ans=(ans+dp[0][i])%MOD;
	}
	cout<<ans<<endl;
	return 0;
}