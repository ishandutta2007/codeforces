#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
const int MAXN=505,MAXM=1e7;
int n,a[MAXN],all[MAXN],b[MAXN];
queue<int> que;
stack<int> stk;
int ans[MAXM],ccf,ansp[MAXM][2],sb;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		while(!que.empty()) que.pop();
		while(!stk.empty()) stk.pop();
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),all[i]=a[i],b[i]=0;
		sort(all+1,all+n+1);
		for(int i=1; i<=n; i++){
			a[i]=lower_bound(all+1,all+n+1,a[i])-all;
			b[a[i]]++;
		}
		bool fuck=1;
		for(int i=1; i<=n; i++)
			if(b[i]&1){
				fuck=0;
				break;
			}
		if(!fuck){
			puts("-1");
			continue;
		}
		for(int i=n; i; i--)
			stk.push(a[i]=all[a[i]]);
		int cnt=0;
		ccf=sb=0;
		while(!stk.empty()){
			if(!que.empty()&&que.front()==stk.top()){
				cnt+=que.size()+1;
				ans[++ccf]=que.size()<<1;
				que.pop();
				stk.pop();
				while(!que.empty()){
					int x=que.front();
					sb++;
					ansp[sb][0]=cnt;
					ansp[sb][1]=x;
					stk.push(x);
					que.pop();
					cnt++;
				}
			}else{
				que.push(stk.top());
				stk.pop();
			}
		}
		printf("%d\n",sb);
		for(int i=1; i<=sb; i++)
			printf("%d %d\n",ansp[i][0],ansp[i][1]);
		printf("%d\n",ccf);
		for(int i=1; i<=ccf; i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}