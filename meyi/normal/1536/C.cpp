#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=5e5+10;
int a[maxn],m,n,t_case;
char s[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline pii simp(int x,int y){
	ri g=gcd(x,y);
	return {x/g,y/g};
}
map<pii,int>p;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		ri cnt1=0,cnt2=0;
		p.clear();
		for(ri i=1;i<=n;++i){
			if(s[i]=='D')++cnt1;
			else ++cnt2;
			pii k=simp(cnt1,cnt2);
			printf("%d ",++p[k]);
		}
		puts("");
	}
	return 0;
}