#include<bits/stdc++.h>
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
void read(vector<char>&s) {
	char c=getchar(); s.emplace_back(0);
	while(c!='.'&&c!='X') c=getchar();
	while(c=='.'||c=='X') s.emplace_back(c), c=getchar();
}

const int N=1e6+9;
int n,m,q,g[N],sg[N];
vector<char>s[N];

int main() {
	n=read(), m=read();
	rep(i,1,n) read(s[i]);
	rep(p,1,m-1) {
		rep(i,1,n-1) if(s[i+1][p]=='X'&&s[i][p+1]=='X') {g[p]=1; break;}
	}
	rep(j,1,m) sg[j]=sg[j-1]+g[j];
	q=read();
	while(q--) {
		int x=read(), y=read()-1, res=sg[y]-sg[x-1];
		if(res) puts("NO");
		else puts("YES");
	}
	return 0;
}