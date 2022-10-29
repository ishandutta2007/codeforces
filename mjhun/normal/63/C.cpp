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

int n;
int a[16],b[16],c[16];
int q0[16],q1[16];

bool can(int k){
	fore(j,0,10)q0[j]=0;
	int p=1;
	fore(_,0,4){
		int d=k/p%10;p*=10;
		if(q0[d])return false;
		q0[d]++;
	}
	fore(i,0,n){
		fore(j,0,10)q0[j]=q1[j]=0;
		int p=1,bb=0;
		fore(_,0,4){
			int d0=k/p%10,d1=a[i]/p%10;
			if(d0==d1)bb++;
			else q0[d0]++,q1[d1]++;
			p*=10;
		}
		int cc=0;
		fore(j,0,10)cc+=min(q0[j],q1[j]);
		if(b[i]!=bb||c[i]!=cc)return false;
	}
	return true;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d%d%d",a+i,b+i,c+i);
	int r=-1;
	fore(i,0,10000)if(can(i)){
		if(r>=0){puts("Need more data");return 0;}
		r=i;
	}
	if(r<0)puts("Incorrect data");
	else printf("%04d\n",r);
	return 0;
}