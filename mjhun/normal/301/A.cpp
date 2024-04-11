#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

bool v[128];
int x[256];
int r,n,m;

int f(int k){
	int r=0;
	fore(i,0,k)r-=x[i];
	fore(i,k,n)r+=x[i];
	return r;
}

void go(int k){
	if(v[k])return;
	v[k]=true;
	r=max(r,f(k));
	fore(i,0,m+1){
		if(i>k||m-i>n-k)continue;
		go((k-i)+(m-i));
	}
}

int main(){
	r=-(1<<30);
	scanf("%d",&m);n=2*m-1;
	fore(i,0,n)scanf("%d",x+i);
	sort(x,x+n);
	go(0);
	printf("%d\n",r);
	return 0;
}