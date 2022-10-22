#include<cstdio>
inline int maxx(int a,int b){
	if(a>b) return a;
	return b;
}
const int SIZ=105;
int n;
int sum;
bool mrk[SIZ];
int tot,b[SIZ];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		sum+=a;
		if(!mrk[a]){
			mrk[a]=1;
			b[++tot]=a;
		}
	}
	int mx=0;
	for(int i=1;i<=tot;i++){
		for(int j=1;j<i;j++){
			int x=b[i],y=b[j];
			if(x<y){
				int tmp=x;
				x=y,y=tmp;
			}
			for(int k=2;k*k<=x;k++)
				if(x%k==0)
					mx=maxx(mx,(x+y)-(x/k+y*k));
		}
	}
	printf("%d\n",sum-mx);
	return 0;
}