#include<cstdio>
const int N=100002;
int n,cnt,i,j,a[N];
int main(){
	scanf("%d",&n);
	while(n){
		cnt++;
		j=1;
		while(j<=n){
			i=n/j%10;
			if(i)
				a[cnt]+=j,n-=j;
			j*=10;
		}
	}
	printf("%d\n",cnt);
	while(cnt)
		printf("%d\n",a[cnt--]);
}