#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define K (1<<20)
using namespace std;

typedef long long ll;

int ft[K];

void upd(int x){
	for(;x<K;x+=x&-x)ft[x]++;
}

int query(int x){
	int r=0;
	for(;x>0;x-=x&-x)r+=ft[x];
	return r;
}

int x[1<<20];
int l[1<<20];
int r[1<<20];
pair<int,int> xx[1<<20];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",&xx[i].fst),xx[i].snd=i;
	sort(xx,xx+n);
	fore(i,0,n)x[xx[i].snd]=i;
	fore(i,0,n)l[i]=query(K-x[i]-2),upd(K-x[i]-1);
	memset(ft,0,sizeof(ft));
	for(int i=n-1;i>=0;--i)r[i]=query(x[i]+1),upd(x[i]+2);
	ll s=0;
	fore(i,0,n)s+=1LL*l[i]*r[i];
	printf("%I64d\n",s);
	return 0;
}