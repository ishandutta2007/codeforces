#include<stdio.h>
#include<string.h>
int n,m;
int a[111111];
int maxr[111111];
void upd(int&x,int y){
	if(x == -1 || x < y)x=y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d",&a[i*m+j]);
	memset(maxr,-1,sizeof(maxr));
	for(int j=0; j<m; j++){
		int S = 0, E = 0;
		for(int i=1; i<n; i++){
			if(a[i*m+j] >= a[E*m+j])
				E = i;
			else{
//				printf("%d %d\n",S,E);
				upd(maxr[S], E);
				S = E = i;
			}
		}
//		printf("%d %d\n",S,E);
		upd(maxr[S], E);
	}
	for(int i=1; i<n; i++)
		upd(maxr[i], maxr[i-1]);
	int q;
	for(scanf("%d",&q); q--;){
		int x,y;
		scanf("%d%d",&x,&y);--x;--y;
		puts(maxr[x]>=y?"Yes":"No");
	}
	return 0;
}