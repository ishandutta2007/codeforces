#include<cstdio>
const int N=600002;
int n,m,i,j,A[N],B[N],s1,s2,s3,x;
int id[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		id[i]=1;
	for(i=1;i<=m;i++){
		scanf("%d%d",A+i,B+i);
		if(A[i]==1)
			id[B[i]]=0;
		if(B[i]==1)
			id[A[i]]=0;
	}
	for(x=1;x<=n;x++)
		if(id[x]==0)
			break;
	if(x>n){
		printf("-1");
		return 0;
	}	
	for(i=1;i<=m;i++){
		if(A[i]==x&&id[B[i]]==0)
			id[B[i]]=3;
		if(B[i]==x&&id[A[i]]==0)
			id[A[i]]=3;
	}
	for(i=1;i<=n;i++)
		if(id[i]==0)
			id[i]=2;
	for(i=1;i<=n;i++){
		if(id[i]==1)s1++;
		if(id[i]==2)s2++;
		if(id[i]==3)s3++;
	}
	if(1ll*s1*s2+1ll*s2*s3+1ll*s1*s3!=m||s1==0||s2==0||s3==0){
		printf("-1");
		return 0;
	}
	for(i=1;i<=m;i++)
		if(id[A[i]]==id[B[i]]){
			printf("-1");
			return 0;
		}
	for(i=1;i<=n;i++)
		printf("%d ",id[i]);
	//while(1);
}