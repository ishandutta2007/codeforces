#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int lim=500,maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
vector<int>pri;
bool is[maxn];
inline void sieve(int siz){
	pri.clear();
	is[1]=true;
	for(ri i=2;i<=siz;++i){
		if(!is[i])pri.push_back(i);
		for(auto j:pri){
			if(i*j>siz)break;
			is[i*j]=true;
			if(i%j==0)break;
		}
	}
}
inline int pfac(ll k){
	for(auto i:pri)
		if(k%i==0)
			return i;
	return 1;
}
int n,t_case;
typedef pair<int,int> pii;
#define fi first
#define se second
inline ll ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	ll ret;
	scanf("%lld",&ret);
	return ret;
}
int ans[maxn];
ll l[110][110];
inline void print(){
	printf("!");
	for(ri i=1;i<=n;++i)printf(" %d",ans[i]);
	printf("\n");
	fflush(stdout);
}
signed main(){
	srand(time(0));
	sieve(200000);
	reverse(pri.begin(),pri.end());
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		if(n<100){
			vector<pii>v;
			for(ri i=1;i<n;++i)
				for(ri j=i+1;j<=n;++j){
					l[i][j]=l[j][i]=ask(i,j);
					v.emplace_back(i,j);
				}
			sort(v.begin(),v.end(),[](const pii &x,const pii &y){return l[x.fi][x.se]>l[y.fi][y.se];});
			ri mx=0;
			for(auto i:v){
				if(ans[i.fi]||ans[i.se])continue;
				ri cur=(1+(int)sqrt(4*l[i.fi][i.se]+1))>>1;
				if(!mx)mx=cur;
				for(ri j=1;j<=n;++j)
					if(j!=i.fi&&j!=i.se)
						if(l[i.fi][j]%cur){
							ans[i.se]=cur;
							break;
						}
				if(!ans[i.se])ans[i.fi]=cur;
			}
			for(ri i=1;i<=n;++i)
				if(!ans[i]){
					ans[i]=mx-n+1;
					break;
				}
		}
		else if(n<10000){
			ri mx=0;
			pii pos={0,0};
			for(ri i=1;i<=n;i+=2){
				ll tmp=(i==n)?ask(n-1,n):ask(i,i+1);
				ri fac=pfac(tmp);
				if(fac>mx)mx=fac,pos=(i==n)?pii{n-1,n}:pii{i,i+1};
			}
			ri poss=0;
			for(ri i=1;i<=n;++i)
				if(i!=pos.fi&&i!=pos.se){
					if(ask(i,pos.fi)%mx==0)ans[poss=pos.fi]=mx;
					else ans[poss=pos.se]=mx;
					break;
				}
			for(ri i=1;i<=n;++i)
				if(i!=poss)
					ans[i]=ask(poss,i)/mx;
		}
		else{
			for(ri T=n/25;T;--T){
				auto rnd=[](){return rand()%n+1;};
				ri x=rnd(),y=rnd();
				while(x==y)y=rnd();
				ll tmp=ask(x,y);
				ri p1=pfac(tmp),p2=tmp/p1;
				if(p1>lim&&p2>lim&&p2<200001&&!is[p2]){
					while(1){
						ri z=rnd();
						while(x==z||y==z)z=rnd();
						ll tmp=ask(x,z);
						if(tmp%p1){
							ans[x]=p2,ans[y]=p1;
							break;
						}
						if(tmp%p2){
							ans[x]=p1,ans[y]=p2;
							break;
						}
					}
				}
			}
			ri mx=0;
			for(ri i=1;i<=n;++i)
				if(ans[i]>ans[mx])
					mx=i;
			for(ri i=1;i<=n;++i)
				if(!ans[i]){
					ll tmp=ask(mx,i)/ans[mx];
					if(tmp>lim){
						ans[i]=tmp;
						if(!is[tmp]&&tmp>ans[mx])mx=i;
					}
				}
			for(ri i=1;i<=n;++i)
				if(!ans[i])
					ans[i]=ask(mx,i)/ans[mx];
		}
		print();
		fill(ans,ans+n+1,0);
	}
	return 0;
}