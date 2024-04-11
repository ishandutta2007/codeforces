#include <stdio.h>
#include <algorithm>

int parent[101],rank[101],srt[100],a[101][100],i,amount;

bool qwe(int i1,int i2){
	return a[i][i1]>a[i][i2];
}

bool sortpar(int i1,int i2){
	return parent[i1]>parent[i2];
}

void make_set(int v){
	parent[v]=v;
	rank[v]=0;
	amount++;
}

int find_set(int v){
	if(parent[v]==v){
		return v;
	}
	return parent[v]=find_set(parent[v]);
}

void union_sets(int a,int b){
	a=find_set(a);
	b=find_set(b);
	if(a!=b){
		if(rank[a]<rank[b]){
			parent[a]=b;
		}
		else{
			parent[b]=a;		
			if(rank[a]==rank[b]){
				++rank[a];
			}
		}
		amount--;
	}
}

int main(){
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	amount=0;
	int k,n,m,c,j,r;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m+1;j++){
			a[j][i]=0;
		}
	}
	for(i=0;i<n;i++){
		scanf("%d",&k);
		a[0][i]=k;
		for(j=0;j<k;j++){
			scanf("%d",&c);
			a[c][i]=1;
		}
		make_set(i);
		srt[i]=i;
	}
/*	for(i=1;i<m+1;i++){
		for(j=0;j<n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	for(i=1;i<m+1;i++){
		std::sort(srt,srt+n,qwe);
/*		for(j=0;j<n;j++){
			printf("%d ",srt[j]);
		}
		printf("\n");
		for(j=0;j<n;j++){
			printf("%d ",a[i][srt[j]]);
		}
		printf("\n");*/
		j=1;
		while(j<n && a[i][srt[j]]==1){
//			printf("%d %d\n",srt[j],srt[j-1]);
			union_sets(srt[j],srt[j-1]);
			j++;
		}
	}
	c=0;
	for(i=0;i<n;i++){
		c+=a[0][i];
	}
	if(c!=0){
		printf("%d",amount-1);
	}
	else{
		printf("%d",amount);
	}
}