#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;
int a[100005];
int x[100005];

ll doit(){
	ll s=0,r=0,ms=0;
	fore(i,0,n-1){
		s+=x[i];
		r=max(r,s-ms);
		ms=min(ms,s);
	}
	return r;
}

int main(){
	scanf("%d",&n);
	ll r=0;
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n-1){
		x[i]=abs(a[i]-a[i+1]);
		if(i%2)x[i]=-x[i];
	}
	r=doit();
	fore(i,0,n-1){
		x[i]=abs(a[i]-a[i+1]);
		if(i%2==0)x[i]=-x[i];
	}
	r=max(r,doit());
	printf("%lld\n",r);
	return 0;
}