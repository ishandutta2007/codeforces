#include<cstdio>
#include<cstdlib>
#include<map>
#include<algorithm>
using namespace std;
const int N=10000002;
int x,y,p,q[N],s,e,a,b;
map<int,int>vis,pre,cnt;
int ksm(int x,int b){
	int s=1;
	while(b){
		if(b&1)
			s=1ll*s*x%p;
		b>>=1;
		x=1ll*x*x%p;
	}
	return s;
}
int inv(int x){
	return ksm(x,p-2);
}
void Out1(int a){
	if(a==x)
		return;
	Out1(pre[a]);
	if((pre[a]+1)%p==a)
		printf("1 ");
	else
		if((pre[a]+p-1)%p==a)
			printf("2 ");
		else
			printf("3 ");
}
void Out2(int a){
	if(a==y)
		return;
	if((a+1)%p==pre[a])
		printf("1 ");
	else
		if((a+p-1)%p==pre[a])
			printf("2 ");
		else
			printf("3 ");
	Out2(pre[a]);
}
void G(int a,int b){
	if(!vis[b]){
		q[++e]=b;
		vis[b]=vis[a];
		pre[b]=a;
		cnt[b]=cnt[a]+1;
	}
	else
		if(vis[a]!=vis[b]){
			if(vis[a]==2)
				a^=b^=a^=b;
			printf("%d\n",cnt[a]+cnt[b]+1);
			Out1(a);
			if(b==(a+1)%p)
				printf("%d ",1);
			else
				if(b==(a+p-1)%p)
					printf("%d ",2);
				else
					printf("%d ",3);
			Out2(b);
			//while(1);
			exit(0);
		}
}
int main(){
	scanf("%d%d%d",&x,&y,&p);
	if(x==y){
		printf("0");
		return 0;
	}
	e=-1;
	q[++e]=x;
	vis[x]=1;
	q[++e]=y;
	vis[y]=2;
	while(s<=e){
		a=q[s++];
		b=(a+1)%p;
		G(a,b);
		b=(a+p-1)%p;
		G(a,b);
		b=inv(a);
		G(a,b);
	}
}