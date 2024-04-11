#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int f[100001],a[100001];
vector<int>g[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		scanf("%d",&f[i]),g[f[i]].push_back(i);
	for(int i=n;i;i--){
		if(!g[i].size())a[i]=1;
		else for(int j=0;j<g[i].size();j++)
			a[i]+=a[g[i][j]];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		printf("%d%c",a[i],i==n?'\n':' ');
}