#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=105;
int n;
int a[MAXN],p[MAXN];
int Query(){
	putchar('?');
	for(int i=1; i<=n; i++)
		printf(" %d",a[i]);
	puts("");
	fflush(stdout);
	/*
	static int s[MAXN],vis[MAXN];
	for(int i=1; i<=n; i++)
		s[i]=a[i]+p[i];
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			if(s[i]==s[j]) return i;
	return 0;
	*/
	int res;
	scanf("%d",&res);
	return res;
}
int main(){
	scanf("%d",&n);
	//for(int i=1; i<=n; i++) scanf("%d",p+i);
	a[n]=1;
	p[n]=n;
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++)
			a[j]=i+1;
		if(!Query()){
			p[n]=i;
			break;
		}
	}
	for(int i=1; i<=n; i++){
		if(i==p[n]) continue;
		if(p[n]+1-i<=0){
			a[n]=i+1-p[n];
			for(int j=1; j<n; j++)
				a[j]=1;
		}else{
			a[n]=1;
			for(int j=1; j<n; j++)
				a[j]=p[n]+1-i;
		}
		p[Query()]=i;
		//if(Query()==n) printf("%d\n",i);
	}
	putchar('!');
	for(int i=1; i<=n; i++)
		printf(" %d",p[i]);
	puts("");
	fflush(stdout);
	return 0;
}