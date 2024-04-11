#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
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
		T ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
};
BIT<int>tt;
int a[maxn],m,n,t_case;
vector<int>pos[26];
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s%s",&n,s+1,t+1);
		tt.mx_idx=n;tt.clear();
		for(ri i=0;i<26;++i)pos[i].clear();
		for(ri i=n;i;--i){
			s[i]-='a',t[i]-='a';
			pos[s[i]].push_back(i);
		}
		ll ans=LLONG_MAX,sum=0;
		for(ri i=1;i<=n;++i){
			for(ri j=0;j<t[i];++j)
				if(pos[j].size()){
					ri go=pos[j].back();
					ckmin(ans,sum+tt.query(n-go+1)+go-i);
				}
			if(pos[t[i]].empty())break;
			ri nxt=pos[t[i]].back();
			sum+=tt.query(n-nxt+1)+nxt-i;
			tt.add(n-nxt+1,1);
			pos[t[i]].pop_back();
		}
		printf("%lld\n",ans==LLONG_MAX?-1:ans);
	}
	return 0;
}