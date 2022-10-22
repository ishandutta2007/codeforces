#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
int n;
int op[MAXN],a[MAXN],ans[MAXN];
priority_queue<int> que;
bool Calc(){
	for(int i=n*2;i;i--){
		if(op[i]){
			if(!que.empty()&&-que.top()<a[i]) return 0;
			que.push(-a[i]);
		}else{
			if(que.empty()) return 0;
			ans[++*ans]=-que.top();
			que.pop();
		}
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n*2; i++){
		char s[5];
		scanf("%s",s);
		if(s[0]=='+') op[i]=0;
		else op[i]=1,scanf("%d",a+i);
	}
	if(Calc()){
		puts("YES");
		for(int i=n;i;i--) printf("%d ",ans[i]);
		puts("");
	}else puts("NO");
	return 0;
}