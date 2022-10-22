#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m1,m2;
int father[N],father2[N],vis[N];
int find(int x){
	if(father[x]!=x){
		father[x]=find(father[x]);
	}
	return father[x];
}
void join(int x,int y){
	int fx=find(x),fy=find(y);
	father[fx]=fy;
}
int find2(int x){
	if(father2[x]!=x){
		father2[x]=find2(father2[x]);
	}
	return father2[x];
}
void join2(int x,int y){
	int fx=find2(x),fy=find2(y);
	father2[fx]=fy;
}
int sum,ans1[N],ans2[N];
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;i++)father[i]=father2[i]=i;
	for(int i=1;i<=m1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		join(u,v);
	}
	for(int i=1;i<=m2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		join2(u,v);
	}
	for(int i=1;i<=n;i++){
		for(int o=1;o<=n;o++){
			if(find(o)==find(i)||find2(o)==find2(i))continue;
			else{
				sum++;
				ans1[sum]=i;
				ans2[sum]=o;
				join(o,i);
				join2(o,i);
			}
		}
	}
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++){
		printf("%d %d\n",ans1[i],ans2[i]);
	}
	
	
}