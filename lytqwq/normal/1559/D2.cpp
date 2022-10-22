#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m1,m2;
int father[N],father2[N];
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
int sum,ans1[N],ans2[N],q1[N],qq1,q2[N],qq2;
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
	for(int i=2;i<=n;i++){
		if(find(1)!=find(i)&&find2(1)!=find2(i)){
			join(1,i);
			join2(1,i);
			sum++;
			ans1[sum]=1;
			ans2[sum]=i;
		}
	}
	for(int i=2;i<=n;i++){
		if(find(1)!=find(i)&&find2(1)==find2(i)){
			q1[++qq1]=i;
			join(1,i);
			join2(1,i);
		}
		if(find(1)==find(i)&&find2(1)!=find2(i)){
			q2[++qq2]=i;
			join(1,i);
			join2(1,i);
		}
	}
	for(int i=1;i<=min(qq1,qq2);i++){
		join(q2[i],q1[i]);
		join2(q2[i],q1[i]);
		sum++;
		ans1[sum]=q1[i];
		ans2[sum]=q2[i];
	}
	printf("%d\n",sum);
	for(int i=1;i<=sum;i++){
		printf("%d %d\n",ans1[i],ans2[i]);
	}
	
	
}