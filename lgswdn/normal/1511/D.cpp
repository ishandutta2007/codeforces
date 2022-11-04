#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
typedef pair<int,int>pii;
const int N=29;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,k;
bool vst[N][N];
vector<char>ans;

void dfs(int u) {
	rep(v,1,k) {
		if(!vst[u][v]) vst[u][v]=1,dfs(v);
	}
	ans.push_back('a'+u-1);
}

int main() {
	n=read(), k=read();
	dfs(1);
	ans.pop_back();
	int p=0;
	while(p<n) {
		for(auto c:ans) {
			if(p<n) putchar(c), p++;
		}
	}
	return 0;
}