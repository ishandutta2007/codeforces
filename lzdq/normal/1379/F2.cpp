#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=2e5+5,B=400,NB=MAXN/B+5;
int n,m,q;
set<pr> s;
int cnt[NB];
set<int> s0[MAXN],s1[MAXN];
int mx[MAXN],mi[MAXN],b0[NB],b1[NB];
bool ans;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1; i<=n; i++)
		mi[i]=m+1;
	for(int i=1; i<=(n+B-1)/B; i++)
		b1[i]=m+1;
	while(q--){
		int x,y,c;
		scanf("%d%d",&x,&y);
		auto it=s.find(mkp(x,y));
		if(it==s.end()){
			s.insert(mkp(x,y));
			c=1;
		}else{
			s.erase(it);
			c=-1;
		}
		if(x&1){
			x=x+1>>1;
			y=y+1>>1;
			if(c==1) s1[x].insert(y),mi[x]=min(mi[x],y);
			else{
				s1[x].erase(s1[x].find(y));
				if(s1[x].empty()) mi[x]=m+1;
				else mi[x]=*s1[x].begin();
			}
		}else{
			x=x+1>>1;
			y=y+1>>1;
			if(c==1) s0[x].insert(y),mx[x]=max(mx[x],y);
			else{
				s0[x].erase(s0[x].find(y));
				if(s0[x].empty()) mx[x]=0;
				else{
					auto it=s0[x].end();
					it--;
					mx[x]=*it;
				}
			}
		}
		int w=(x+B-1)/B;
		int l=(w-1)*B+1,r=min(n,w*B);
		b0[w]=0;
		b1[w]=m+1;
		*cnt-=cnt[w];
		cnt[w]=0;
		for(int i=r; i>=l; i--){
			b0[w]=max(b0[w],mx[i]);
			b1[w]=min(b1[w],mi[i]);
			if(b0[w]>=mi[i]) cnt[w]=1;
		}
		*cnt+=cnt[w];
		if(!*cnt){
			ans=1;
			int t=0;
			for(int i=(n+B-1)/B; i; i--){
				if(t>=b1[i]){
					ans=0;
					break;
				}
				t=max(t,b0[i]);
			}
		}else ans=0;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}