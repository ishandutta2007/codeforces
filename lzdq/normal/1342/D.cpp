#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int MAXN=2e5+5;
int n,k,m[MAXN],c[MAXN];
int pre[MAXN],cnt[MAXN];
vector<int> vec[MAXN];
multiset<int> s;
int ans;
int main(){
	//freopen("in2.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",m+i),s.insert(m[i]);
	for(int i=1; i<=k; i++){
		scanf("%d",c+i);
		if(c[i]==c[i-1]) pre[i]=pre[i-1];
		else pre[i]=i-1;
	}
	while(!s.empty()){
		int u=k,sum=0;
		ans++;
		//printf("ans %d\n",ans);
		while(u){
			multiset<int>::iterator it=s.upper_bound(u);
			if(it==s.begin()) break;
			it--;
			//printf("it %d\n",*it);
			vec[ans].push_back(*it);
			s.erase(it);
			sum++;
			if(sum==c[u]) u=pre[u];
		}
		//puts("");
	}
	printf("%d\n",ans);
	for(int i=1; i<=ans; i++){
		printf("%d ",vec[i].size());
		for(int j=0; j<vec[i].size(); j++)
			printf("%d ",vec[i][j]);
		puts("");
	}
	return 0;
	return 0;
}