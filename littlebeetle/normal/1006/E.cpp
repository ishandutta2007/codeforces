#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200020;
vector<int>t[N];
int n,m,i,k,a,d[N],p[N],s[N],T;
void dfs(int i){
	d[i]=++T;
	p[T]=i;
	sort(t[i].begin(),t[i].end());
	for(unsigned j=0;j<t[i].size();j++){
		dfs(t[i][j]);
		s[i]+=s[t[i][j]];
	}
	s[i]++;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=2;i<=n;i++){
		scanf("%d",&a);
		t[a].push_back(i);
	}
	dfs(1);
	while(m--){
		scanf("%d%d",&i,&k);
		printf("%d\n",s[i]<k?-1:p[d[i]+k-1]);
	}
	return 0;
}