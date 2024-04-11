#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
#define pb push_back
#define pp pop_back
#define eb emplace_back
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define RALL(k) k.rend(),k.rbegin()
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxn];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		ri ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<int>c;
int cnt[4],id[256],n,t_case;
vector<int>pos[4];
char rid[5]="ANOT",s[maxn],t[maxn];
int main(){
	id['A']=0,id['N']=1,id['O']=2,id['T']=3;
	for(scanf("%d",&t_case);t_case--;){
		scanf("%s",s+1);
		n=strlen(s+1);
		c.mx_idx=n;
		memset(cnt,0,sizeof cnt);
		for(ri i=0;i<4;++i)pos[i].clear();
		for(ri i=n;i;--i){
			s[i]=id[s[i]];
			++cnt[s[i]];
			pos[s[i]].pb(i);
		}
		vector<int>ans,ord({0,1,2,3});
		ll b=-1;
		t[n+1]=0;
		do{
			ri l=0;
			vector<int>poss[4]=pos;
			for(ri i=0;i<4;++i)
				for(ri j=1;j<=cnt[ord[i]];++j)
					t[++l]=ord[i];
			c.clear();
			ll sum=0;
			for(ri i=1;i<=n;++i){
				ri tmp=poss[t[i]].back();
				poss[t[i]].pp();
				sum+=c.query(tmp+1,n);
				c.add(tmp,1);
			}
			if(sum>b)b=sum,ans=ord;
		}while(next_permutation(ALL(ord)));
		for(ri i=0;i<4;++i)
			for(ri j=1;j<=cnt[ans[i]];++j)
				putchar(rid[ans[i]]);
		putchar(10);
		fflush(stdout);
	}
	return 0;
}