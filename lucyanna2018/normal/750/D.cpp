#include<stdio.h>
#include<string.h>
bool a[333][333][8],b[333][333][8],r[333][333];
const int dx[8]={1,1,0,-1,-1,-1,0,1};
const int dy[8]={0,1,1,1, 0, -1,-1,-1};
int main(){
	int n;
	a[150][150][0] = true;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int l;
		scanf("%d",&l);
		memset(b,0,sizeof(b));
		for(int x=0; x<=300; x++)
		for(int y=0; y<=300; y++)
		for(int d=0; d<8; d++)
		if(a[x][y][d]){
			for(int j=1; j<=l; j++){
				r[x+dx[d]*j][y+dy[d]*j] = true;
			}
			b[x+dx[d]*l][y+dy[d]*l][(d+1)%8] = true;
			b[x+dx[d]*l][y+dy[d]*l][(d+7)%8] = true;
		}
		memcpy(a,b,sizeof(b));
	}
	int res=0;
	for(int x=0; x<=300; x++)
		for(int y=0; y<=300; y++)
			if(r[x][y])
				res++;
	printf("%d\n",res);
	return 0;
}