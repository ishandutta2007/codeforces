#include<cstdio>
#include<map>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
int n,k;
int id;
int ans[MAXN],cnt;
queue<int> que;
map<int,bool> f;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&id);
		if(!f[id]){
			if(que.size()==k){
				f[que.front()]=0;
				que.pop();
			}
			que.push(id);
			f[id]=1;
		}
	}
	while(!que.empty())
		ans[++cnt]=que.front(),que.pop();
	printf("%d\n",cnt);
	for(int i=cnt;i>0;i--)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}