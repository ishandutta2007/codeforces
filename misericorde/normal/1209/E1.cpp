#include <bits/stdc++.h>
int n,m,G[5][1000],tl=0,t;
struct nd {
	int v,i,j;
}a[1000];nd node(int v,int i,int j){
	nd nw;nw.v=v;nw.i=i;nw.j=j;
	return nw;
}int cmp(nd a, nd b){
	return a.v<b.v;
}
int main(){
	scanf("%d",&t);
	while (t--){
		tl=0;
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i){
			for (int j=1;j<=m;++j){
				scanf("%d",&G[i][j]);
				a[++tl]=node(G[i][j],i,j);
			}
		}std::sort(a+1,a+tl+1,cmp);
		if (n==1){printf("%d\n",a[tl].v);}
		if (n==2){printf("%d\n",a[tl].v+a[tl-1].v);}
		if (n==3){printf("%d\n",a[tl-1].v+a[tl].v+a[tl-2].v);}
		if (n==4){
			int ans=0;
			for (int i=tl-1;i>=3;i--){
				for (int j=i-1;j>=2;j--){
					for (int k=j-1;k>=1;k--){
						int d1=0,d2=0;
						if (a[tl].j==a[i].j&&a[j].j==a[k].j){
							d1=abs(a[tl].i-a[i].i);d2=abs(a[j].i-a[k].i);}
						if (a[tl].j==a[j].j&&a[i].j==a[k].j){
							d1=abs(a[tl].i-a[j].i);d2=abs(a[i].i-a[k].i);}
						if (a[tl].j==a[k].j&&a[i].j==a[j].j){
							d1=abs(a[tl].i-a[k].i);d2=abs(a[i].i-a[j].i);}
						if (d1==3)d1=1;
						if (d2==3)d2=1;
						if ((d1==2&&d2==1)||(d1==1&&d2==2))continue;
						ans=std::max(ans,a[tl].v+a[i].v+a[j].v+a[k].v);
					}
				}
			}printf("%d\n",ans);
		}

	}
		
	return 0;
}