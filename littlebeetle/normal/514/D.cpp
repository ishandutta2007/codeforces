#include<cstdio>
const int N=100002,K=19;
int n,m,k,i,j,Lg[N],ans,f[5];
struct ST{
	int i,j,a[N],f[N][K];
	int max(int x,int y){
		return x>y?x:y;
	}
	void pre(){
		for(j=0;(1<<j+1)<=n;j++)
			for(i=1;i+(1<<j+1)<=n+1;i++)
				f[i][j+1]=max(f[i][j],f[i+(1<<j)][j]);
	}
	int Query(int l,int r){
		int j=Lg[r-l+1];
		return max(f[l][j],f[r-(1<<j)+1][j]);
	}	
}T[5];
bool check(int len){
	for(int i=1,j,s;i+len<=n+1;i++){
		s=0;
		for(j=0;j<m;j++)
			s+=T[j].Query(i,i+len-1);
		if(s<=k){
			if(len>ans){
				ans=len;
				for(j=0;j<m;j++)
					f[j]=T[j].Query(i,i+len-1);
			}	
			return 1;
		}
	}
	return 0;
}
void work(){
	int l=1,r=n,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	check(l);
	for(i=0;i<m;i++)
		printf("%d ",f[i]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&T[j].a[i]),T[j].f[i][0]=T[j].a[i];
	for(Lg[0]=-1,i=1;i<=n;i++)
		Lg[i]=Lg[i>>1]+1;
	for(i=0;i<m;i++)
		T[i].pre();
	work();
	return 0;
}