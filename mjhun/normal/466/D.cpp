#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n,h;
int x[2048];

int f(int k, int s){
	if(k==n)return s<2;
	if(x[k]+s==h){
		return (1LL*(s+1)*f(k+1,s))%MOD;
	}
	else if(x[k]+s+1==h){
		return f(k+1,s+1);
	}
	else if(x[k]+s-1==h){
		return (1LL*s*f(k+1,s-1))%MOD;
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&h);
	fore(i,0,n)scanf("%d",x+i);
	printf("%d\n",f(0,0));
	return 0;
}