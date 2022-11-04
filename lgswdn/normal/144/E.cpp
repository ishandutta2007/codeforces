#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

int n,m;
vi ans;
vector<pii>s[100009];
priority_queue<pii>q;

int main() {
	n=read(), m=read();
	rep(i,1,m) {
		int r=n+1-read(), c=read();
		s[r].emplace_back(pii(-c,i));
	}
	rep(i,1,n) {
		for(auto p:s[i]) q.push(p);
		while(!q.empty()&&-q.top().fi<i) q.pop();
		if(!q.empty()) ans.emplace_back(q.top().se), q.pop();
	}
	printf("%Ld\n",ans.size()); for(auto x:ans) printf("%d ",x); puts("");
	return 0; //
}