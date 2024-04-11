#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,ans,a;
priority_queue<int>q;

signed main() {
	n=read();
	rep(i,1,n) {
		q.push(a=read()-i);
		if(a<q.top()) q.push(a), ans+=q.top()-a, q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}