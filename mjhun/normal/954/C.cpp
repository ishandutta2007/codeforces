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
#define mcpy(a,b) memcpy(a,b,sizeof(a))
#define N 1000000000
using namespace std;
typedef long long ll;

void perdi(){puts("NO");exit(0);}

int m,k;
int a[200005];

void check(){
	fore(i,0,k-1){
		if(a[i]+1==a[i+1]){
			if(a[i]%m==m-1)perdi();
		}
		else if(a[i]-1==a[i+1]){
			if(a[i]%m==0)perdi();
		}
	}
}

int main(){
	scanf("%d",&k);
	fore(i,0,k)scanf("%d",a+i),a[i]--;
	m=-1;
	fore(i,0,k-1){
		if(a[i]==a[i+1])perdi();
		int d=abs(a[i]-a[i+1]);
		if(d==1)continue;
		if(m<0)m=d;
		else if(m!=d)perdi();
	}
	if(m<0)m=N;
	else check();
	printf("YES\n%d %d\n",N,m);
	return 0;
}