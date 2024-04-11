#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct node{
	int h,w,id;
	inline bool operator<(const node &k)const{
		return h<k.h;
	}
}a[maxn];
struct cmp{
	inline bool operator()(const int &x,const int &y){
		return a[x].w<a[y].w;
	}
};
set<int,cmp>s;
int ans[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%d%d",&a[i].h,&a[i].w);
			if(a[i].h<a[i].w)swap(a[i].h,a[i].w);
			a[i].id=i;
		}
		sort(a+1,a+n+1);
		s.clear();
		for(ri i=1,lst=1;i<=n;++i){
			if(a[lst].h<a[i].h){
				while(lst<i)s.insert(lst++);
			}
			auto it=s.lower_bound(i);
			if(it==s.begin())ans[a[i].id]=-1;
			else ans[a[i].id]=a[*--it].id;
		}
		for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}