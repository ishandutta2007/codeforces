#include<cstdio>
const int MAXN=2e5+5;
int q,h,n;
int p[MAXN];
int ans;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&h,&n);
		ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d",p+i);
		if(n==1){
			puts("0");
			continue;
		}
		int j=h;
		for(int i=2;i<n;i++){
			if(p[i+1]+1==p[i]) j=p[++i];
			else ans++,h=p[i];
		}
		if(p[n]>1&&j!=p[n]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
/*

4
3 1
3 
8 6
8 7 6 5 3 2
9 6
9 8 5 4 3 1
1 1
1


*/