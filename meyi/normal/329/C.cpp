#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],m,n;
mt19937 rnd(time(0));
unordered_set<int>s[maxn];
signed main(){
	clock_t st=clock();
	scanf("%d%d",&n,&m);
	for(ri i=1,x,y;i<=m;++i){
		scanf("%d%d",&x,&y);
		s[x].insert(y),s[y].insert(x);
	}
	iota(a+1,a+n+1,1);
	for(ri T=100;T;--T){
		shuffle(a+1,a+n+1,rnd);
		vector<int>v;
		for(ri i=1;i<=n;++i)
			if(!s[a[i]].count(a[i==n?1:i+1])){
				v.push_back(i);
				if(v.size()==m){
					for(ri j:v)printf("%d %d\n",a[j],a[j==n?1:j+1]);
					return 0;
				}
			}
	}
	puts("-1");
	return 0;
}