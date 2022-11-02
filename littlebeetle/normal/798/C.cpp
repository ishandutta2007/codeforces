#include<cstdio>
const int N=200002;
int n,i,a[N],x,ans;
int gcd(int x,int y){
	if(x==0||y==0)return x+y;
	return y?gcd(y,x%y):x;
}
int main(){
	printf("YES\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		x=gcd(x,a[i]);
	}
	if(x>1){
		printf("0");
		return 0;
	}
	for(i=1;i<n;i+=2){
		if(a[i]%2&&a[i+1]%2)
			ans++;
		else{
			if(a[i]%2&&a[i+1]%2==0)
				ans+=2;
			else
				if(a[i]%2==0&&a[i+1]%2==1)
					i--;
		}
	}
	if(i==n&&a[n]%2)
		ans+=2;
	printf("%d",ans);
	//while(1);
}