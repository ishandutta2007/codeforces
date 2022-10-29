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
using namespace std;
typedef long long ll;

void perdi(){puts("No");exit(0);}

int n;ll t;
ll a[200005],b[200005];
int x[200005];
int s[200005];
bool w[200005]; // true si no lo muevo

bool valid(){
	//fore(i,0,n)printf(" %lld",b[i]);
	fore(i,0,n-1)if(b[i]>b[i+1])return false;
	fore(i,1,n){
		if(w[i]){
			if(a[i]+t<=b[i-1])return false;
		}
		else {
			if(a[i]+t>b[i-1])return false;
		}
	}/*
	fore(i,0,n)if(a[x[i]]+t>b[i])return false;
	fore(i,0,n){
		if(x[i]==n-1)continue;
		if(a[x[i]+1]+t<=b[i])return false;
	}*/
	return true;
}

int main(){
	scanf("%d%lld",&n,&t);a[n]=1LL<<61;
	fore(i,0,n)scanf("%lld",a+i);
	fore(i,0,n)scanf("%d",x+i),x[i]--;
	fore(i,0,n){
		if(x[i]<i)perdi();
		if(i<n-1&&x[i]>x[i+1])perdi();
		s[i+1]++;
		s[x[i]+1]--;
		w[x[i]+1]=true;
	}
	int tt=0;
	fore(i,0,n){
		tt+=s[i];
		if(tt&&w[i])perdi();
		if(!tt)w[i]=true;
	}
	w[n]=true;
	fore(i,0,n){
		if(w[i+1])b[i]=a[i]+t;
		else b[i]=a[i+1]+t;
		if(i&&b[i-1]>=b[i])b[i]=b[i-1]+1;
	}
	if(!valid())perdi();
	puts("Yes");
	fore(i,0,n)printf("%lld%c",b[i]," \n"[i==n-1]);
	return 0;
}