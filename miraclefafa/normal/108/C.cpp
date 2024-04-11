#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
struct Object {
	int u,v,d;
};
bool operator < (Object a,Object b) {
	return a.u<b.u;
}
int n,m,i,j,u,v,d,In[2000],Ou[2000],D[2000];
Object tmp;
vector<Object> ans;
int main() {
	scanf("%d%d",&n,&m);
	memset(In,-1,sizeof(In));
	memset(Ou,-1,sizeof(Ou));
	for (i=1;i<=m;i++) scanf("%d%d%d",&u,&v,&d),In[v]=u,Ou[u]=v,D[u]=d;
	for (i=1;i<=n;i++) if (In[i]==-1 && Ou[i]!=-1) {
		for (j=i,d=D[i];Ou[j]!=-1;j=Ou[j]) d=min(d,D[j]);
		tmp.u=i;tmp.v=j;tmp.d=d;
		ans.push_back(tmp);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (i=0;i<ans.size();i++) printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].d);
}