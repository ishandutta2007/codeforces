#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define j0 PORONGON

int n;
int q2[1024][1024];
int q5[1024][1024];
int f0[1024][1024];
int f1[1024][1024];
int i0=-1,j0=-1;

void doit(int q[][1024], int f[][1024]){
	f[n-1][n-1]=q[n-1][n-1];
	for(int i=n-1;i>=0;--i){
		for(int j=n-1;j>=0;--j){
			if(i==n-1&&j==n-1)continue;
			f[i][j]=1<<30;
			if(i<n-1)f[i][j]=min(f[i][j],f[i+1][j]);
			if(j<n-1)f[i][j]=min(f[i][j],f[i][j+1]);
			f[i][j]+=q[i][j];
		}
	}
}

void doit2(int q[][1024], int f[][1024]){
	int i=0,j=0;
	printf("%d\n",f[i][j]);
	while(i<n-1||j<n-1){
		if(j==n-1||i<n-1&&f[i+1][j]<f[i][j+1]){
			putchar('D');i++;
		}
		else {
			putchar('R');j++;
		}
	}
	puts("");
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)fore(j,0,n){
		int x;
		scanf("%d",&x);
		if(!x){i0=i;j0=j;q2[i][j]=q5[i][j]=50;continue;}
		while(x%2==0){x/=2;q2[i][j]++;}
		while(x%5==0){x/=5;q5[i][j]++;}
	}
	doit(q2,f0);doit(q5,f1);
	if(i0>=0&&min(f0[0][0],f1[0][0])>1){
		puts("1");
		int i=0,j=0;
		while(i<i0||j<j0){
			if(i<i0){putchar('D');i++;}
			else {putchar('R');j++;}
		}
		while(i<n-1||j<n-1){
			if(i<n-1){putchar('D');i++;}
			else {putchar('R');j++;}
		}
		puts("");
		return 0;
	}
	if(f0[0][0]<f1[0][0])doit2(q2,f0);
	else doit2(q5,f1);
	return 0;
}