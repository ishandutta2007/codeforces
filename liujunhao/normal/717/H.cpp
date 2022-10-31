#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXT 1000000
#define MAXN 50000
#define MAXE 100000
#define MAXL 20
int bl[MAXN+10],u[MAXE+10],v[MAXE+10],c[MAXT+10],T,n,e,a[MAXN+10][MAXL+10];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
inline int Get_rand(int l,int r){
	return l+rand()%(r-l+1);
}
void read(){
	Read(n),Read(e);
	int i,j;
	for(i=1;i<=e;i++)
		Read(u[i]),Read(v[i]);
	for(i=1;i<=n;i++){
		Read(*a[i]);
		for(j=1;j<=*a[i];j++){
			Read(a[i][j]);
			T=max(T,a[i][j]);
		}
	}
}
bool solve(){
	int i,cnt=0;
	for(i=1;i<=n;i++)
		bl[i]=a[i][Get_rand(1,*a[i])];
	for(i=1;i<=T;i++)
		c[i]=rand()&1;
	for(i=1;i<=e;i++)
		if((cnt+=(c[bl[u[i]]]!=c[bl[v[i]]]))>=((e+1)>>1))
			return 1;
	return 0;
}
void print(){
	int i;
	for(i=1;i<=n;i++)
		printf("%d ",bl[i]);
	puts("");
	for(i=1;i<=T;i++)
		printf("%d ",2-c[i]);
}
int main()
{
	srand(20000305);
	read();
	while(!solve());
	print();
}
// haha