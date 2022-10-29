#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("-1");exit(0);}

int n;
ll x[100005];

map<ll,int> p2;
int c[64];
int cc[64];

int main(){
	ll p=1;int k=0;
	while(p<=1000000000000LL){
		p2[p]=k;
		p*=2;
		k++;
	}
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",x+i);
	fore(i,0,n)if(p2.count(x[i]))c[p2[x[i]]]++;
	int r=0;
	for(int i=n-1;i>=0;--i)if(!p2.count(x[i])){
		r++;
		int k=0;
		while(c[k]){
			c[k]--;
			k++;
		}
		if(x[i]>(1LL<<k))perdi();
	}
	fore(i,1,64)while(c[i]>c[i-1]){
		r++;
		if(!c[i-1])perdi();
		c[i]--;
		int k=0;
		while(c[k]){
			c[k]--;
			k++;
		}
	}
	bool pp=false;
	for(int i=r+(c[0]+1)/2;i<=r+c[0];++i){
		bool can=true;
		int kk=i-r;
		int k=kk;
		fore(j,0,64)if(c[j]>kk)k-=c[j]-kk;
		can=k>=0;
		if(can){
			if(pp)putchar(' ');
			pp=true;
			printf("%d",i);
		}
	}
	if(!pp)printf("-1");
	puts("");
	return 0;
}