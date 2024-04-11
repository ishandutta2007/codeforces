#include<cstdio>
const int N=500002,K=21;
int n,m,x,y,a,b,t[N],i,j,f[N][K],s;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<N;i++)
		t[i]=i;
	while(n--){
		scanf("%d%d",&x,&y);
		t[x]=max(t[x],y);
	}
	for(i=0;i<N;i++)
		t[i]=max(t[i],i>=1?t[i-1]:0),
		f[i][0]=t[i];
	for(j=0;j+1<K;j++)
		for(i=0;i<N;i++)
			f[i][j+1]=f[f[i][j]][j];
	while(m--){
		scanf("%d%d",&a,&b);
		s=0;
		for(i=K-1;i>=0;i--)
			if(f[a][i]>a&&f[a][i]<b){
				s+=1<<i;
				a=f[a][i];
			}
		if(t[a]>=b)
			printf("%d\n",s+1);
		else
			printf("-1\n");
	}
	//while(1);
}