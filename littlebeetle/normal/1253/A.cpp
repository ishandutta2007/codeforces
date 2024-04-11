#include<cstdio>
const int N=300002;
int q,n,i,j,k,l,r,a[N],b[N],t;
long long s;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		l=r=k=0;
		s=0;
		t=1;
		for(i=1;i<=n;i++){
			scanf("%d",b+i);
			a[i]=b[i]-a[i];
			if(a[i]<0)
				t=0;
			if(a[i]){
				if(!l)l=i;
				r=i;
				if(k){
					if(k!=a[i])
						t=0;
				}
				else
					k=a[i];
				s+=a[i];
			}
		}
		if(t&&(r-l+1)*1ll*k==s)
			printf("YES\n");
		else
			printf("NO\n");
	}
}