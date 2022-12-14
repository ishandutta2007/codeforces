#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define mo 1000000007
#define N 200005
int n,m,a[N],ex[N*4];
int ji,ou,pji,pou,ans;
std::map<int,int> f;
int main(){
	scanf("%d%d",&n,&m);
	if(m>4*n) m=4*n;
	rpt(i,1,m) ex[i]=0;
	rpt(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]<=m) ex[a[i]]=1;
	}
	ji=ou=0;
	rpt(i,1,n){
		if(f[a[i]]){
			a[i]=-1;continue;
		}
		f[a[i]]=1;
		if(a[i]&1) ji++;else ou++;
	}
	pji=1;pou=2;
	rpt(i,1,n) if(a[i]==-1){
		if(ji>ou){
			while(ex[pou]&&pou<=m) pou+=2;
			if(pou>m){
				printf("-1");exit(0);
			}
			a[i]=pou;pou+=2;ou++;ans++;
		}
		else{
			while(ex[pji]&&pji<=m) pji+=2;
			if(pji>m){
				printf("-1");exit(0);
			}
			a[i]=pji;pji+=2;ji++;ans++;
		}
	}
	if(ji>ou){
		rpt(i,1,n) if(a[i]&1){
			while(ex[pou]&&pou<=m) pou+=2;
			if(pou>m){
				printf("-1");exit(0);
			}
			a[i]=pou;pou+=2;ou++;ji--;ans++;
			if(ji==ou) break;
		}
	}
	else if(ji<ou){
		rpt(i,1,n) if(a[i]%2==0){
			while(ex[pji]&&pji<=m) pji+=2;
			if(pji>m){
				printf("-1");exit(0);
			}
			a[i]=pji;pji+=2;ji++;ou--;ans++;
			if(ji==ou) break;
		}
	}
	printf("%d\n",ans);
	rpt(i,1,n) printf("%d ",a[i]);
}