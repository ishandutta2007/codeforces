#include<cstdio>
const int N=100020;
int n,m,a[N],s[N],p[N],t,i,l,r,mid;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	a[s[t=1]=n+1]=1<<30;
	for(i=n;i;i--){
		if(a[i]<=a[s[t]]){
			p[i]=-1;
			if(a[i]<a[s[t]])
				s[++t]=i;
		}
		else{
			l=1;r=t;
			while(l<r){
				mid=l+r>>1;
				if(a[s[mid]]>=a[i])
					l=mid+1;
				else
					r=mid;
			}
			p[i]=s[r]-i-1;
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",p[i]);
}