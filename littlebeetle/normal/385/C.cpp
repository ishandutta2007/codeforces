#include<cstdio>
const int N=10000004;
int n,i,j,k,a[N],p[N],x,l,r,s[N];
bool f[N];
void prepare(){
	for(i=2;i<N;i++){
		if(!f[i])a[k++]=i,p[i]=i;
		for(j=0;i*a[j]<N&&(!j||i%a[j-1]);j++){
			f[i*a[j]]=1;
			p[i*a[j]]=a[j];
		}
	}
}
int main(){
	prepare();
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		while(x!=1){
			if((x/p[x])%p[x])
				s[p[x]]++;
			x/=p[x];
		}
	}
	for(i=1;i<N;i++)
		s[i]+=s[i-1];
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&l,&r);
		if(l>=N)l=N-1;
		if(r>=N)r=N-1;
		printf("%d\n",s[r]-s[l-1]);
	}
	return 0;
}