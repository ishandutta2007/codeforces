#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=3e5+5,MAXP=1e7;
int n,k,top;
int cntp,rt;
int ch[MAXP][2],id[MAXP],val[MAXP];
map<int,vector<pr> > mp;
vector<int> ans;
int main(){
	scanf("%d%d",&n,&k);
	if(k==0){
		printf("%d\n",n);
		for(int i=1; i<=n; i++)
			printf("%d ",i);
		puts("");
		return 0;
	}
	top=k;
	while(top&top-1) top&=top-1;
	top=__builtin_ctz(top);
	for(int i=1; i<=n; i++){
		int a; scanf("%d",&a);
		mp[a>>top+1].push_back(mkp(a,i));
	}
	for(auto a:mp){
		rt=++cntp;
		int res=1,p;
		for(pr x:a.second){
			int v=x.first;
			int u=rt;
			for(int i=29; ~i; i--){
				if(!ch[u][v>>i&1]) ch[u][v>>i&1]=++cntp;
				u=ch[u][v>>i&1];
			}
			id[u]=x.second;
			val[u]=v;
			p=x.second;
			int t=rt;
			for(int i=29; t&&~i; i--){
				int b=(v>>i&1)^1;
				if(!ch[t][b]) b^=1;
				t=ch[t][b];
			}
			if(t&&(val[t]^v)>=k){
				res=2;
				ans.push_back(x.second);
				ans.push_back(id[t]);
				break;
			}
		}
		if(res==1) ans.push_back(p);
	}
	if(ans.size()<2) puts("-1");
	else{
		printf("%d\n",(int)ans.size());
		for(int i:ans) printf("%d ",i);
		puts("");
	}
	return 0;
}