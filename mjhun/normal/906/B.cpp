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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int randd(){return abs(rand()|(rand()<<15));}
int r[100005];
int n,m;

bool check(int i, int j){
	int a=r[i],b=r[j];
	int am=a%m;
	if(am&&a-1==b)return false;
	if(a<m-1&&a+1==b)return false;
	if(a-m==b)return false;
	if(a+m==b)return false;
	return true;
}

bool valid(){
	/*fore(i,0,n){
		fore(j,0,m){
			if(j)putchar(' ');
			printf("%d",r[i*m+j]+1);
		}
		puts("");
	}
	puts("");*/
	fore(i,0,n)fore(j,0,m){
		int k=i*m+j;
		if(j&&!check(k,k-1))return false;
		if(j<m-1&&!check(k,k+1))return false;
		if(i&&!check(k,k-m))return false;
		if(i<n-1&&!check(k,k+m))return false;
	}
	return true;
}

int px[100005],py[100005];
int rr[100005];

int main(){
	srand(time(0));
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		puts("YES\n1");
		return 0;
	}
	if(n==2&&m==2||min(n,m)==1&&max(n,m)<=3||min(n,m)==2&&max(n,m)==3){
		puts("NO");
		return 0;
	}
	fore(i,0,n*m)r[i]=i;
	if(n<=3||m<=3){
		do {
			random_shuffle(r,r+n*m);
		} while(!valid());
	}
	else {
		int k=0;
		fore(i,0,n/2)px[k++]=2*i+1;
		fore(i,0,(n+1)/2)px[k++]=2*i;
		k=0;
		fore(i,0,m/2)py[k++]=2*i+1;
		fore(i,0,(m+1)/2)py[k++]=2*i;
		fore(i,0,n)fore(j,0,m)rr[i*m+j]=r[px[i]*m+py[j]];
		memcpy(r,rr,sizeof(r));
		assert(valid());
	}
	puts("YES");
	fore(i,0,n){
		fore(j,0,m){
			if(j)putchar(' ');
			printf("%d",r[i*m+j]+1);
		}
		puts("");
	}
	return 0;
}