#include<cstdio>
int n;
int Calc(int a,int b){
	int res=0;
	while(b--)
		res=res*10+a;
	return res;
}
int ans;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<10;i++)
			for(int j=1;j<10;j++)
				if(Calc(i,j)<=n) ans++;
		printf("%d\n",ans);
	}
	return 0;
}