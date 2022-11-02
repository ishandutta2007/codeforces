#include<cstdio>
const int N=1002;
int n,m,i,j,tmp,t[N],l[N],r[N],s[N],a[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",t+i,l+i,r+i);
		if(t[i]==1)
			s[l[i]]++,s[r[i]]--;
	}
	for(i=1;i<=n;i++)
		s[i]+=s[i-1];
	a[1]=n;
	for(i=2;i<=n;i++)
		if(s[i-1])
			a[i]=a[i-1];
		else
			a[i]=a[i-1]-1;
	for(i=1;i<=m;i++)
		if(t[i]==0){
			tmp=0;
			for(j=l[i];j<r[i];j++)
				if(a[j]>a[j+1])
					tmp=1;
			if(tmp==0){
				printf("NO");
				return 0;
			}
		}
	printf("YES\n");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	//while(1);
}