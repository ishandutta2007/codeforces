#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define mp make_pair
using namespace std;
typedef long long ll;

#define MAXN 2505

ll ft[MAXN+1][MAXN+1];int n,m,q;
void upd(int i0, int j0, ll v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)
	for(int j=j0+1;j<=MAXN;j+=j&-j)ft[i][j]+=v;
}
ll get(int i0, int j0){
	ll r=0;
	for(int i=i0;i;i-=i&-i)
	for(int j=j0;j;j-=j&-j)r+=ft[i][j];
	return r;
}

map<pair<pair<int,int>,pair<int,int> >,ll> w;

ll randd(){
	return ((1LL*rand())<<48)|((1LL*rand())<<32)|((1LL*rand())<<16)|rand();
}

int main(){
	srand(666);
	scanf("%d%d%d",&n,&m,&q);
	fore(_,0,q){
		int t,r1,c1,r2,c2;
		scanf("%d%d%d%d%d",&t,&r1,&c1,&r2,&c2);r1--;c1--;
		if(t==1){
			ll s=randd();
			w[mp(mp(r1,c1),mp(r2,c2))]=s;
			upd(r1,c1,s);upd(r1,c2,-s);upd(r2,c1,-s);upd(r2,c2,s);
		}
		else if(t==2){
			ll s=-w[mp(mp(r1,c1),mp(r2,c2))];
			upd(r1,c1,s);upd(r1,c2,-s);upd(r2,c1,-s);upd(r2,c2,s);
		}
		else {
			r1++;c1++;
			puts(get(r1,c1)==get(r2,c2)?"Yes":"No");
		}
	}
	return 0;
}