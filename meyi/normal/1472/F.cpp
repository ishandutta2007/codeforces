#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
typedef pair<int,int> pii;
#define fi first
#define se second
const pii null={-1,-1};
int m,n,t_case;
map<int,int>p;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&m,&n);
		p.clear();
		for(ri i=1,x,y;i<=n;++i){
			scanf("%d%d",&x,&y);
			p[y]+=x;
		}
		bool flag=false;
		pii lst=null;
		for(auto i:p){
			if(lst==null){
				if(i.se!=3)lst=i;
			}
			else{
				if(i.se==3||(i.se!=lst.se&&((i.fi-lst.fi)&1))||(i.se==lst.se&&!((i.fi-lst.fi)&1)))flag=true;
				lst=null;
			}
		}
		puts((flag||lst!=null)?"NO":"YES");
	}
	return 0;
}