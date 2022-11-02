#include<cstdio>
const int N=1000020;
int n,m,a[N],p[N],cnt,l,r,x,y=-1;
int main(){
	scanf("%d%d",&n,&m);
	for(l=r=1;r<=n;r++){
		scanf("%d",a+r);
		if(p[a[r]]==0)
			cnt++;
		p[a[r]]++;
		while(cnt>m){
			if(p[a[l]]==1)
				cnt--;
			p[a[l]]--;
			l++;
		}
		if(r-l>y-x)
			x=l,y=r;
	}
	printf("%d %d",x,y);
	//while(1);
}