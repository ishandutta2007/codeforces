#include<cstdio>
const int MAXN=2e5+5;
int n,p[MAXN],q[MAXN];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",p+i),q[p[i]]=i;
		int s=0;
		for(int i=1;i<=n;i++){
			int x=q[i];
			if(x>1&&p[x-1]<i) s++;
			if(x<n&&p[x+1]<i) s++;
			if(s==i-1) putchar('1');
			else putchar('0');
		}
		puts("");
	}
	return 0;
}