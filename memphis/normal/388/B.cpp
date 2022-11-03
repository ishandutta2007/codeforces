#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1005
#define rep(i,x,y) for(int i=x;i<=y;++i)

int K,N,p;
bool f[maxn][maxn];

void mk(int x){
	++N;
	f[N][2]=f[2][N]=true;
	for(int tmp=K;tmp!=1;tmp>>=1){
		f[N+1][N]=f[N][N+1]=true;
		f[N+2][N]=f[N][N+2]=true;
		f[N+3][N+1]=f[N+1][N+3]=true;
		f[N+3][N+2]=f[N+2][N+3]=true;
		N+=3;
	}
	f[1][N]=f[N][1]=true;
}

inline int lowbit(int x){return x&-x;}

int num(int x){
	int sum=0;
	for(;x;x>>=1)++sum;
	return sum-1;
}

int build(int x,int y){
	f[N+1][x*3+3]=f[x*3+3][N+1]=true;
	++N;
	rep(i,1,(y-x<<1)-1){
		f[N+1][N]=f[N][N+1]=true;
		++N;
	}
	return N;
}

int main(){
	scanf("%d",&K);
	if(K==1){
		puts("2");
		puts("NY");
		puts("YN");
		return 0;
	}
	
	N=2;
	int n=1;
	for(;n<=K;n<<=1);
	n>>=1;
	mk(n);
	
	int xx=num(n);
	K-=n;
	
	for(int tmp=K;tmp;tmp-=lowbit(tmp)){
		int pp=num(lowbit(tmp));
	//	printf("%d\n",pp);
		int sp=build(pp,xx);
		f[1][sp]=f[sp][1]=true;
	}
	printf("%d\n",N);
	rep(i,1,N){
		rep(j,1,N)
			if(f[i][j])putchar('Y');
		else putchar('N');
		puts("");
	}
}