#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

signed main() {
	int u=read(), v=read();
	if(u>v) puts("-1");
	else if((v-u)%2) puts("-1");
	else if(v==0) puts("0");
	else if(u==v) printf("1\n%lld\n",u);
	else {
		int a=u, b=(v-u)/2, c=(v-u)/2;
		if(((a+b)^c)==u) printf("2\n%lld %lld\n",(a+b),c);
		else printf("3\n%lld %lld %lld\n",a,b,c);
	}
	return 0;
}