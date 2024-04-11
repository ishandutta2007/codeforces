#include<stdio.h>
#include<vector>
using namespace std;
#define ran 666666
int N, n;
bool st[ran];
int A[ran],B[ran];

int ace[ran];
int ancestor(int x){return x-ace[x]?ace[x]=ancestor(ace[x]):x;}
void merge(int x,int y){
	ace[ancestor(x)]=ancestor(y);
}

int main(){
	scanf("%d%d",&N,&n);
	for(int i=1; i<=N; i++){
		int x;
		scanf("%d",&x);
		st[i] = (bool)x;
		A[i] = B[i] = -1;
	}
	for(int i=0; i<n; i++){
		int y,z;
		for(scanf("%d",&y); y--;){
			scanf("%d",&z);
			if(A[z] == -1)A[z] = i;else
				B[z] = i;
		}
	}
	for(int i=0; i<n+n; i++)
		ace[i] = i;
	for(int i=1; i<=N; i++){
		int x = A[i], y = B[i];
		if(st[i]){
			merge(x,y);
			merge(x+n,y+n);
		}else{
			merge(x,y+n);
			merge(y,x+n);
		}
	}
	bool fl = true;
	for(int i=0; i<n; i++)
		if(ancestor(i) == ancestor(i+n))
			fl = false;
	puts(fl?"YES":"NO");
	return 0;
}