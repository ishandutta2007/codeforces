#include <stdio.h>
#include <algorithm>

int parent[101],rank[101],x[101],y[101],srt[101];

bool sortx(int i1,int i2){
	return x[i1]<x[i2];
}

bool sorty(int i1,int i2){
	return y[i1]<y[i2];
}

void make_set(int v){
	parent[v]=v;
	rank[v]=0;
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
	}
}

int main(){
	#pragma comment(linker, "/STACK:268435456")
	#ifndef ONLINE_JUDGE
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	#endif
	int n,i,r;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		make_set(i);
		scanf("%d%d",&x[i],&y[i]);
		srt[i]=i;
	}
	std::sort(srt,srt+n,sortx);
	for(i=1;i<n;i++){
		if(x[srt[i]]==x[srt[i-1]]){
			union_sets(srt[i],srt[i-1]);
		}
	}
	std::sort(srt,srt+n,sorty);
	for(i=1;i<n;i++){
		if(y[srt[i]]==y[srt[i-1]]){
			union_sets(srt[i],srt[i-1]);
		}
	}
	for(i=0;i<n;i++){
		parent[i]=find_set(i);
	}
	std::sort(parent,parent+n);
	r=0;
	for(i=1;i<n;i++){
		if(parent[i]!=parent[i-1]){
			r++;
		}
	}
	printf("%d",r);
}