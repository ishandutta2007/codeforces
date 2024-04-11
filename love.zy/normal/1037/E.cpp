#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[200001];
int a[200001][2],deg[200001];
bool used[200001];
int ans[200001],sum;
queue<int> q;
inline void check(int i,int k){
	if(!used[i]){
		used[i]=true;
		if(deg[a[i][0]]--==k){
			q.push(a[i][0]);sum--;
		}
		if(deg[a[i][1]]--==k){
			q.push(a[i][1]);sum--;
		}
	}
}
int main()
{
	int n,m,k,x,y;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(i);
		v[y].push_back(i);
		deg[x]++;deg[y]++;
		a[i][0]=x;a[i][1]=y;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]<k)q.push(i);
		else sum++;
	}
	for(int i=m-1;i>=0;i--){
		while(!q.empty()){
			int t=q.front();q.pop();
			for(int j:v[t])
				check(j,k);
		}
		ans[i]=sum;
		check(i,k);
	}
	for(int i=0;i<m;i++)
		printf("%d\n",ans[i]);
}