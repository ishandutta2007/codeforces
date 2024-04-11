#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("-1");exit(0);}

int a[200005];
int b[200005];
int c[200005];
int q[32];
int n;

int main(){
	scanf("%d",&n);
	ll s=0;
	fore(i,0,n)scanf("%d",b+i),s+=b[i];
	fore(i,0,n)scanf("%d",c+i),s+=c[i];
	if(s%(2*n))perdi();
	s/=2*n;
	fore(i,0,n){
		if(b[i]+c[i]-s<0||(b[i]+c[i]-s)%n)perdi();
		a[i]=(b[i]+c[i]-s)/n;
		fore(j,0,31)if(a[i]&(1<<j))q[j]++;
	}
	fore(i,0,n){
		ll bb=0,cc=0;
		fore(j,0,31){
			if(a[i]&(1<<j)){
				cc+=1LL*n*(1<<j);
				bb+=1LL*q[j]*(1<<j);
			}
			else {
				cc+=1LL*q[j]*(1<<j);
			}
		}
		if(bb!=b[i]||cc!=c[i])perdi();
	}
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",a[i]);
	}
	puts("");
	return 0;
}