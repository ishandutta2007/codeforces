#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 50

int n,cnta,cntb,a[MAXN+10],b[MAXN+10];

template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return ;
		}
}

inline int Quary(int i,int j){
	printf("? %d %d\n",i,j);
	fflush(stdout);
	char c[10];
	scanf("%s",c);
	if(c[0]=='<') return -1;
	else if(c[0]=='=') return 0;
	else return 1;
}
void Divide(int n){
	for(int i=1;i<=n;i+=2){
		int k=Quary(i,i+1),x=i,y=i+1;
		if(k>0) swap(x,y);
		a[++cnta]=x,b[++cntb]=y;
	}
}
inline int Find_mn(){
	int ret=a[1];
	for(int i=2;i<=cnta;i++)
		if(Quary(ret,a[i])>0)
			ret=a[i];
	return ret;
}
inline int Find_mx(){
	int ret=b[1];
	for(int i=2;i<=cntb;i++)
		if(Quary(ret,b[i])<0)
			ret=b[i];
	return ret;
}
void solve(){
	cnta=cntb=0;
	if(n&1){
		Divide(n-1);
		if(Quary(b[cntb],n)>0) a[++cnta]=n;
		else b[++cntb]=n;
	}
	else Divide(n);
	int mn=Find_mn(),mx=Find_mx();
	printf("! %d %d\n",mn,mx);
	fflush(stdout);
}
int main()
{
	int T;
	Read(T);
	while(T--){
		Read(n);
		if(n==1){
			printf("! 1 1\n");
			fflush(stdout);
			continue;
		}
		solve();
	}
	return 0;
}