#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=2e5+9;
typedef pair<int,char> pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,pre[N],nxt[N],cnt;
bool d[N];
char s[N];

void dk(int x) {
	nxt[pre[x]]=nxt[x], pre[nxt[x]]=pre[x];
}
void del(int x,int y) {
	dk(x), dk(y), cnt-=2, d[x]=d[y]=1;
	if(s[pre[x]]=='A'&&s[nxt[y]]=='B') del(pre[x],nxt[y]);
	else return;
}

int main() {
	int T=read();
	while(T--) {
		scanf("%s",s+1); n=strlen(s+1); cnt=n;
		rep(i,1,n) pre[i]=i-1, nxt[i]=i+1, d[i]=0;
		s[0]=s[n+1]='*';
		rep(i,1,n-1) if(s[i]=='A'&&!d[i]) {
			if(!d[nxt[i]]&&s[nxt[i]]=='B') del(i,nxt[i]);
		}
		rep(i,1,n-1) if(s[i]=='B'&&!d[i]) {
			if(!d[nxt[i]]&&s[nxt[i]]=='B') del(i,nxt[i]);
		}
		printf("%d\n",cnt);
	}
	return 0;
}