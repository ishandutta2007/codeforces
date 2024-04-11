#include <bits/stdc++.h>
#define snd second
#define pb push_back
#define fst first
#define mp make_pair
#define fore(i,a,n) for(int i = a, qwer = n;i<qwer;i++)
#define INF (1<<20)
using namespace std;
typedef long long ll;

int n;
int a[128];
int b[128];
int s;
int f0[128][10005]; // min
int f1[128][10005]; // max

void go(int k, int s){
	if(f0[k][s]>=0)return;
	int r0,r1;
	if(k==n){
		if(s!=0)r0=INF;
		else r0=0;
		r1=0;
	}
	else {
		go(k+1,s);
		r0=f0[k+1][s];
		r1=f1[k+1][s];
		int rr0,rr1,ss=max(s-b[k],0);
		go(k+1,ss);
		rr0=1+f0[k+1][ss];
		rr1=a[k]+f1[k+1][ss];
		if(rr0<r0||rr0==r0&&rr1>r1){
			r0=rr0;
			r1=rr1;
		}
	}
	f0[k][s]=r0;
	f1[k][s]=r1;
}

int main() {
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),s+=a[i];
	fore(i,0,n)scanf("%d",b+i);
	memset(f0,-1,sizeof(f0));
	memset(f1,-1,sizeof(f1));
	go(0,s);
	printf("%d %d\n",f0[0][s],s-f1[0][s]);
	return 0;
}