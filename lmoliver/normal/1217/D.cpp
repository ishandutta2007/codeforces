#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5050;
const int M=5050;
int n,m;
vector<int> es[N];
int in[N]={0};
bool ok(){
	static queue<int> q;
	int c=n;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			q.push(i);
			c--;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(vector<int>::iterator it=es[x].begin();it!=es[x].end();++it){
			if(--in[*it]==0){
				q.push(*it);
				c--;
			}
		}
	}
	return c==0;
}
int k;
int ans[M];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ans[i]=u<v?1:2;
		es[u].push_back(v);
		in[v]++;
	}
	if(ok()){
		k=1;
		for(int i=1;i<=n;i++){
			ans[i]=1;
		}
	}
	else{
		k=2;
	}
	printf("%d\n",k);
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}