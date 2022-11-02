#include<cstdio>
const int N=100002;
int n,i,j,k,a[N],x[N],y[N],cnt,s,u,v;
bool f[N],t[N];
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		if(!f[i])a[k++]=i;
		for(j=0;i*a[j]<=n&&(!j||i%a[j-1]);j++)
			f[i*a[j]]=1;
	}
	for(i=n;i>1;i--)
		if(!f[i]){
			s=0;
			for(j=i;j<=n;j+=i)
				if(t[j]==0)
					s++;
			if(s%2==0){
				u=0;
				for(j=i;j<=n;j+=i)
					if(t[j]==0){
						t[j]=1;
						if(!u)
							u=j;
						else{
							++cnt;
							x[cnt]=u;
							y[cnt]=j;
							u=0;
						}
					}
			}
			else{
				u=0;
				for(j=i;j<=n;j+=i)
					if(t[j]==0&&j!=i*2){
						t[j]=1;
						if(!u)
							u=j;
						else{
							++cnt;
							x[cnt]=u;
							y[cnt]=j;
							u=0;
						}
					}				
			}	
		}
		printf("%d\n",cnt);
		while(cnt)
			printf("%d %d\n",x[cnt],y[cnt]),cnt--;
}