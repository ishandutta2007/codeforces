#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5005;
int n,k,m;
struct Queue{
	int head,tail,que[MAXN];
	inline void push(int x){
		que[tail++]=x;
	}
	inline void pop(){
		head++;
	}
	inline void popb(){
		tail--;
	}
	inline bool empty(){
		return head==tail;
	}
	inline int front(){
		return que[head];
	}
	inline int back(){
		return que[tail-1];
	}
}que[MAXN];
int a[MAXN];
ll f[MAXN][MAXN];
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	f[0][0]=0;
	que[0].push(0);
	n++;
	m++;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(que[j-1].empty()) continue;
			if(que[j-1].front()<i-k) que[j-1].pop();
			if(que[j-1].empty()) continue;
			f[i][j]=f[que[j-1].front()][j-1]+a[i];
		}
		for(int j=1; j<=m; j++){
			if(!f[i][j]) continue;
			//printf("%d %d f %lld\n",i,j,f[i][j]);
			while(!que[j].empty()&&f[que[j].back()][j]<=f[i][j]) que[j].popb();
			que[j].push(i);
		}
	}
	if(!f[n][m]) puts("-1");
	else printf("%lld\n",f[n][m]);
	return 0;
}