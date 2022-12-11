#include<cstdio>
#include<algorithm>
using namespace std;

int a[1001];
int main(){
	for(int i=2;i<=1000;i++){
		for(int j=2;j*j<=i;j++)
			if(i%j==0)goto ed1;
		a[++a[0]]=i;
		ed1:;
	}
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		for(int i=1;i<=a[0];i++){
			int p=0,q=0;
			while(u%a[i]==0)u/=a[i],p++;
			while(v%a[i]==0)v/=a[i],q++;
			if(p>q)swap(p,q);
			if(q>2*p||(p+q)%3)goto ed;
		}
		if(u>v)swap(u,v);
		if(1ll*u*u!=v)goto ed;
		printf("Yes\n");
		continue;
		ed:printf("No\n");
	}
}