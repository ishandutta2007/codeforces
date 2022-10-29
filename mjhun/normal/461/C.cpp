#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;

#define MAXN 100005
int ft[MAXN+1],x[MAXN+1];
void upd(int i0, int v){
	x[i0]+=v;
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){
	int r=0;
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){return get(i1)-get(i0);}

int n,q,a,b;bool rev;

int main(){
	scanf("%d%d",&n,&q);
	fore(i,0,n)upd(i,1);
	a=0;b=n;rev=false;
	while(q--){
		int t,l;
		scanf("%d%d",&t,&l);
		if(t==1){
			if(rev)l=b-a-l;
			if(2*l<=b-a){
				fore(i,0,l)upd(a+l+i,x[a+l-1-i]);
				a+=l;
				rev=false;
			}
			else {
				l=b-a-l;
				fore(i,0,l)upd(b-l-1-i,x[b-l+i]);
				b-=l;
				rev=true;
			}
		}
		else {
			int r;
			scanf("%d",&r);
			if(rev){
				r=(b-a)-r;
				l=(b-a)-l;
				swap(l,r);
			}
			printf("%d\n",get(a+r)-get(a+l));
		}
	}
	return 0;
}