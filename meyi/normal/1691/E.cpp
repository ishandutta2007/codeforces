#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int c[maxn],id[maxn],l[maxn][2],m,n,r[maxn][2],t_case;
struct cmp0{inline bool operator()(int x,int y)const{return r[x][0]!=r[y][0]?r[x][0]<r[y][0]:x<y;}};
set<int,cmp0>s0;
struct cmp1{inline bool operator()(int x,int y)const{return r[x][1]!=r[y][1]?r[x][1]<r[y][1]:x<y;}};
set<int,cmp1>s1;
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%d",c+i),id[i]=i;
			scanf("%d%d",l[i]+c[i],r[i]+c[i]);
			l[i][c[i]^1]=INT_MAX,r[i][c[i]^1]=INT_MIN,vis[i]=false;
		}
		sort(id+1,id+n+1,[&](int x,int y){return l[x][c[x]]<l[y][c[y]];});
		s0.clear(),s1.clear();
		for(ri ii=1;ii<=n;++ii){
			ri i=id[ii];
			if(c[i]){
				r[0][0]=l[i][1];
				auto it=s0.lower_bound(0);
				while(it!=s0.end()){
					ri j=*it;
					it=s0.erase(it);
					ckmin(l[i][0],l[j][0]),ckmax(r[i][0],r[j][0]);
					ckmin(l[i][1],l[j][1]),ckmax(r[i][1],r[j][1]);
					vis[j]=true;
				}
			}
			else{
				r[0][1]=l[i][0];
				auto it=s1.lower_bound(0);
				while(it!=s1.end()){
					ri j=*it;
					it=s1.erase(it);
					ckmin(l[i][0],l[j][0]),ckmax(r[i][0],r[j][0]);
					ckmin(l[i][1],l[j][1]),ckmax(r[i][1],r[j][1]);
					vis[j]=true;
				}
			}
			s0.insert(i),s1.insert(i);
		}
		printf("%d\n",n-accumulate(vis+1,vis+n+1,0));
	}
	return 0;
}