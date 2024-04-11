#include<cstdio>
const int N=300002,M=9000020;
int n,i,j,k,p,x,a[N],b,t[M][2],s[M],_=1;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(p=1;p<=n;p++){
		scanf("%d",&x);
		s[1]++;
		for(i=30,j=1;i>=0;i--){
			k=x>>i&1;
			//printf("%d\n",k);
			if(!t[j][k])
				t[j][k]=++_;
			j=t[j][k];
			s[j]++;
		}
	}
	//printf("%d\n",t[1][1]);
	for(p=1;p<=n;p++){
		x=a[p];
		b=0;
		s[1]--;
		for(i=30,j=1;i>=0;i--){
			k=x>>i&1;
			//printf("%d %d %d %d\n",k,s[t[j][k]],t[j][k],t[j][k^1]);
			if(s[t[j][k]])
				j=t[j][k];
			else
				j=t[j][k^1],b+=1<<i;
			s[j]--;
		}
		printf("%d ",b);
	}
	//while(1);
}