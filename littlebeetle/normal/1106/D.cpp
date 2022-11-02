#include<cstdio>
#include<queue>
using namespace std;
const int N=200002;
priority_queue<int,vector<int>,greater<int> >Q;
int n,m,i,j,k,a,b,h[N],t[N],v[N],g[N];
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	Q.push(1);
	g[1]=1;
	while(n--){
		i=Q.top();
		Q.pop();
		printf("%d ",i);
		for(j=h[i];j;j=t[j])
			if(!g[v[j]])
				Q.push(v[j]),g[v[j]]=1;
	}
}