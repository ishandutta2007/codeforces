#include<cstdio>

using namespace std;

int cx(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int o;
	scanf("%d",&o);
	return o;
}
int a[51][51],b[51][51];
int f[51][51][51][51],g[51][51][51][51];
int main(){
	int n;
	scanf("%d",&n);
	a[1][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!((i+j)&1)){
				if(i==1&&j==1)continue;
				else if(i==1)a[i][j]=a[i][j-2]^!cx(i,j-2,i,j);
				else if(j==1)a[i][j]=a[i-2][j]^!cx(i-2,j,i,j);
				else a[i][j]=a[i-1][j-1]^!cx(i-1,j-1,i,j);
			}
	for(int i=3;i<=n;i+=2)
		a[2][i]=a[2][i-2]^!cx(2,i-2,2,i);
	for(int i=2;i<=n;i+=2)
		a[1][i]=a[2][i+1]^!cx(1,i,2,i+1);
	for(int i=3;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((i+j)&1)
				a[i][j]=a[i-2][j]^!cx(i-2,j,i,j);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			b[i][j]=a[i][j]^((i+j)&1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int p=1;p+i-1<=n;p++)
				for(int q=1;q+j-1<=n;q++){
					if(i==1&&j==1)f[i][j][p][q]=1;
					else if(i==1)f[i][j][p][q]=a[p][q]==a[p+i-1][q+j-1]?j<=2?1:f[i][j-2][p][q+1]:0;
					else if(j==1)f[i][j][p][q]=a[p][q]==a[p+i-1][q+j-1]?i<=2?1:f[i-2][j][p+1][q]:0;
					else f[i][j][p][q]=a[p][q]==a[p+i-1][q+j-1]?(i>2?f[i-2][j][p+1][q]:0)||(j>2?f[i][j-2][p][q+1]:0)||(f[i-1][j-1][p+1][q]||f[i-1][j-1][p][q+1]):0;
				}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int p=1;p+i-1<=n;p++)
				for(int q=1;q+j-1<=n;q++){
					if(i==1&&j==1)g[i][j][p][q]=1;
					else if(i==1)g[i][j][p][q]=b[p][q]==b[p+i-1][q+j-1]?j<=2?1:g[i][j-2][p][q+1]:0;
					else if(j==1)g[i][j][p][q]=b[p][q]==b[p+i-1][q+j-1]?i<=2?1:g[i-2][j][p+1][q]:0;
					else g[i][j][p][q]=b[p][q]==b[p+i-1][q+j-1]?(i>2?g[i-2][j][p+1][q]:0)||(j>2?g[i][j-2][p][q+1]:0)||(g[i-1][j-1][p+1][q]||g[i-1][j-1][p][q+1]):0;
				}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int p=1;p+i-1<=n;p++)
				for(int q=1;q+j-1<=n;q++)
					if(f[i][j][p][q]!=g[i][j][p][q]&&i+j>=4){
						int o=cx(p,q,p+i-1,q+j-1);
						if(o==f[i][j][p][q]){
							printf("!\n");
							for(int i=1;i<=n;i++)
								for(int j=1;j<=n;j++)
									printf(j==n?"%d\n":"%d",a[i][j]);
							return 0;
						}
						else{
							printf("!\n");
							for(int i=1;i<=n;i++)
								for(int j=1;j<=n;j++)
									printf(j==n?"%d\n":"%d",b[i][j]);
							return 0;
						}
					}
	return 1/0;
}