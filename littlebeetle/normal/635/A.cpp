#include<cstdio>
const int N=102;
int r,c,n,k,x,y,a,b,i,j,ans;
int s[N][N];
int main(){
	scanf("%d%d%d%d",&r,&c,&n,&k);
	while(n--){
		scanf("%d%d",&x,&y);
		s[x][y]++;
	}
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+s[i][j];
	for(a=0;a<r;a++)
		for(b=0;b<c;b++)
			for(x=a+1;x<=r;x++)
				for(y=b+1;y<=c;y++)
					if(s[x][y]-s[x][b]-s[a][y]+s[a][b]>=k)
						ans++;
	printf("%d",ans);
	//while(1);
}