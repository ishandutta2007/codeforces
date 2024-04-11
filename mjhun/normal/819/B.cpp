#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;
ll s;
int n0,n1;
int x[1<<20];
pair<ll,int> r;
int q[1<<20];

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",x+i);x[i]--,
		s+=abs(x[i]-i);
		if(i>=x[i])n0++;
		else n1++;
		q[(x[i]-i+n)%n]++;
	}
	r=mp(s,0);
	fore(i,1,n){
		s+=n0-1-n1;
		s-=n-1-x[n-i];
		s+=x[n-i];
		r=min(r,mp(s,i));
		n0--;
		n1++;
		n1-=q[i];n0+=q[i];
	}
	printf("%lld %d\n",r.fst,r.snd);
	return 0;
}