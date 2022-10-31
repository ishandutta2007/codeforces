#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
#define MAXN 500
int n,a[MAXN+10][MAXN+10],x,y;
long long sr,sc;
void read(){
	Read(n);
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			Read(a[i][j]);
			if(!a[i][j])
				x=i,y=j;
		}
	if(n==1){
		puts("1");
		exit(0);
	}
}
void solve(){
	int i,j;
	long long ts;
	for(i=1;i<=n;i++){
		if(i==x)
			continue;
		ts=0;
		for(j=1;j<=n;j++)
			ts+=a[i][j];
		if(!sr)
			sr=ts;
		else if(ts!=sr){
			puts("-1");
			exit(0);
		}
	}
	for(j=1;j<=n;j++){
		if(j==y)
			continue;
		ts=0;
		for(i=1;i<=n;i++){
			ts+=a[i][j];
		}
		if(!sc)
			sc=ts;
		else if(ts!=sc){
			puts("-1");
			exit(0);
		}
	}
	if(sc!=sr){
		puts("-1");
		exit(0);
	}
	if(x!=y){
		ts=0;
		for(i=1;i<=n;i++)
			ts+=a[i][i];
		if(ts!=sc){
			puts("-1");
			exit(0);
		}
	}
	if(x+y!=n+1){
		ts=0;
		for(i=1;i<=n;i++)
			ts+=a[i][n+1-i];
		if(ts!=sc){
			puts("-1");
			exit(0);
		}
	}
	long long la=ts=0;
	for(j=1;j<=n;j++)
		ts+=a[x][j];
	la=ts;
	ts=0;
	for(i=1;i<=n;i++)
		ts+=a[i][y];
	if(ts!=la){
		puts("-1");
		exit(0);
	}
	if(x==y){
		ts=0;
		for(i=1;i<=n;i++)
			ts+=a[i][i];
		if(ts!=la){
			puts("-1");
			exit(0);
		}
	}
	if(x+y==n+1){
		ts=0;
		for(i=1;i<=n;i++)
			ts+=a[i][n+1-i];
		if(ts!=la){
			puts("-1");
			exit(0);
		}
	}
	if(la>=sr){
		puts("-1");
		exit(0);
	}
	else
		printf("%I64d\n",sc-la);
}
int main()
{
	read();
	solve();
}