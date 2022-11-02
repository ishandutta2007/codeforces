#include<cstdio>
const int N=1000002;
int n,m,a,s[N],p,i,j,k,l,f[9][9],g[9][9],q;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d",&a);
		s[a]++;
	}
	for(i=1;i<=m;i++)
		while(s[i]>8)
			s[i]-=3,p++;
	for(j=0;j<9;j++)
		for(k=0;k<9;k++)
			g[j][k]=-1<<29;
	g[0][0]=0;
	for(i=1;i<=m;i++){
		for(j=0;j<9;j++)
			for(k=0;k<9;k++)
				f[j][k]=-1<<29;
		for(j=0;j<9;j++)
			for(k=0;k<9;k++){
				if(s[i]>2)
					f[k][s[i]-3]=max(f[k][s[i]-3],g[j][k]+1);
				if(s[i]>5)
					f[k][s[i]-6]=max(f[k][s[i]-6],g[j][k]+2);
				if(s[i]&&j&&k)
					f[k-1][s[i]-1]=max(f[k-1][s[i]-1],g[j][k]+1);
				if(s[i]>3&&j&&k)
					f[k-1][s[i]-4]=max(f[k-1][s[i]-4],g[j][k]+2);
				if(s[i]>6&&j&&k)
					f[k-1][s[i]-7]=max(f[k-1][s[i]-7],g[j][k]+3);
				if(s[i]>1&&j>1&&k>1)
					f[k-2][s[i]-2]=max(f[k-2][s[i]-2],g[j][k]+2);
				if(s[i]>4&&j>1&&k>1)
					f[k-2][s[i]-5]=max(f[k-2][s[i]-5],g[j][k]+3);
				if(s[i]>7&&j>1&&k>1)
					f[k-2][s[i]-8]=max(f[k-2][s[i]-8],g[j][k]+4);					
				f[k][s[i]]=max(f[k][s[i]],g[j][k]);
			}
		for(j=0;j<9;j++)
			for(k=0;k<9;k++)
				g[j][k]=f[j][k];
	}		
	for(j=0;j<9;j++)
		for(k=0;k<9;k++)
			q=max(q,f[k][j]);
	printf("%d",p+q);
}