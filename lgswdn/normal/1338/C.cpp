#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

int T,n;

int solve(int x,int y) {
	if(y==0) return x; int s=y/4;
	if(x<s) return solve(x,s);
	else if(x<2*s) return solve(x-s,s)+y/2;
	else if(x<3*s) return solve(x-2*s,s)+3*s;
	else return solve(x-3*s,s)+s;
}

signed main() {
	T=read();
	while(T--) {
		n=read(); int pos=(n-1)/3+1,b=1,s=0;
		while(s<pos) s+=b, b*=4; s-=b/4;
		//cout<<" POS "<<s<<endl;
		pos=pos+b/4-s-1;
		if(n%3==1) printf("%lld\n",pos);
		else if(n%3==2) printf("%lld\n",solve(pos-b/4,b/4)+b/2);
		else printf("%lld\n",(solve(pos-b/4,b/4)+b/2)^pos);
	}
	return 0;
}