#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
vector<int> c[MAXN];
set<pr> st;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			c[i].clear();
		}
		st.clear();
		for(int i=1; i<=n; i++)
			c[a[i]].push_back(i);
		for(int i=1; i<=n; i++)
			if(!c[i].empty()) st.insert(mkp((int)c[i].size(),i));
		auto it=st.end();
		it--;
		int u=c[it->second].back(),v;
		int tmp=a[u];
		for(int i=1; i<n; i++){
			it=st.end();
			it--;
			if(it->second==a[u])
				if(it!=st.begin()) it--;
			v=it->second;
			st.erase(mkp((int)c[a[u]].size(),a[u]));
			c[a[u]].pop_back();
			if(!c[a[u]].empty()) st.insert(mkp((int)c[a[u]].size(),a[u]));
			b[u]=v;
			//printf("u %d v %d\n",u,v);
			u=c[v].back();
		}
		b[u]=tmp;
		for(int i=1; i<=n; i++)
			printf("%d%c",b[i],i==n?'\n':' ');
	}
	return 0;
}