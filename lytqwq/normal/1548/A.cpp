#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int c[N],n,m,q,sum;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		c[min(u,v)]++;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0)sum++;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int opt,u,v;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&u,&v);
			c[min(u,v)]++;
			if(c[min(u,v)]==1)sum--;
		}
		else if(opt==2){
			scanf("%d%d",&u,&v);
			c[min(u,v)]--;
			if(c[min(u,v)]==0)sum++;
		}
		else{
			printf("%d\n",sum);
		}
	}
}