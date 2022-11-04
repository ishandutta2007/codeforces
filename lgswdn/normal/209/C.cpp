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

const int N=1e6+9;
int n,m,id[N],nc[N],deg[N],cnt[N];

int find(int i) {return i==id[i]?i:id[i]=find(id[i]);}

int main() {
	n=read(), m=read();
	rep(i,1,n) id[i]=i;
	rep(i,1,m) {
		int x=read(), y=read(); deg[x]++, deg[y]++;
		x=find(x), y=find(y), id[x]=y;
	}
	rep(i,1,n) cnt[find(i)]+=(deg[i]&1);
	bool flag=1;
	rep(i,1,n) if(deg[i]&&id[i]!=id[1]) flag=0;
	if(flag) return printf("%d\n",cnt[id[1]]/2), 0;
	int ans=0;
	rep(i,1,n) if(i==id[i]) {
		if(i!=1&&deg[i]==0) continue;
		ans++;
		if(cnt[i]) ans+=cnt[i]/2-1;
	}
	printf("%d\n",ans);
	return 0;
}