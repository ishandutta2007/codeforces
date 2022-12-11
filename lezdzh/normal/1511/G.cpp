#include<cstdio>

using namespace std;

int a[200001],l[200001],r[200001],ans[200001];
int c[10000001][2],z[10000001],t;
int qu(int o,int p,int w){
//	int ans2=0,oo=o;
//	for(int i=1;i<=o;i++)
//		if(a[i]&&(i&(1<<w+1)-1)<=p)ans2^=1;
	int ans=0;
	for(int i=w;i>=0;i--){
		if(p>>i&1){
			ans^=z[c[o][0]];
			o=c[o][1];
		}
		else o=c[o][0];
	}
	ans^=z[o];
//	if(w==0)printf("?%d %d???\n",z[c[1][0]],z[c[1][1]]);
//	if(ans!=ans2)printf("??%d %d %d %d %d\n",oo,p,w,ans,ans2);
	return ans;
}
int cx(int o,int u,int v,int w){
	return qu(o,v,w)^qu(o,u,w)^(u<=v?0:qu(o,(1<<w+1)-1,w));
}
int main(){
	int n,m,q;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int o;
		scanf("%d",&o);
		a[o]^=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d",&l[i],&r[i]);
	for(int w=0;w<18;w++){
		while(t){
			c[t][0]=c[t][1]=z[t]=0;
			t--;
		}
		t=m;
		for(int i=1;i<=m;i++){
			int o=i,f=i-1;
			c[o][0]=c[f][0];
			c[o][1]=c[f][1];
			z[o]=z[f];
			if(a[i]){
				z[o]^=1;
				for(int j=w;j>=0;j--){
					int x=i>>j&1;
					c[o][x]=++t;
					c[o][x^1]=c[f][x^1];
					o=c[o][x];
					f=c[f][x];
					c[o][0]=c[f][0];
					c[o][1]=c[f][1];
					z[o]=z[f]^1;
				}
			}
		}
		for(int i=1;i<=q;i++){
			int s=0;
			s^=cx(r[i],(1<<w)-1+l[i]&(1<<w+1)-1,(1<<w+1)-1+l[i]&(1<<w+1)-1,w);
			s^=cx(l[i]-1,(1<<w)-1+l[i]&(1<<w+1)-1,(1<<w+1)-1+l[i]&(1<<w+1)-1,w);
		//	printf("%d %d %d\n",i,w,s);
			ans[i]+=s;
		}
	}
	for(int i=1;i<=q;i++)
		printf(ans[i]==0?"B":"A");
	printf("\n");
}