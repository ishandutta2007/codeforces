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

const int N=3009;
int n,x[N],y[N];
bitset<N>b[N];

struct seg {
	int x,y,d;
}s[N*N];
bool cmp(const seg &a,const seg &b) {return a.d>b.d;}

int main() {
	n=read();
	rep(i,1,n) x[i]=read(), y[i]=read();
	int tot=0;
	rep(i,1,n) rep(j,i+1,n) s[++tot]=(seg){i,j,(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])};
	sort(s+1,s+tot+1,cmp);
	rep(i,1,tot) {
		int x=s[i].x,y=s[i].y;
		b[x][y]=b[y][x]=1;
		if((b[x]&b[y]).any()) return printf("%.10lf\n",sqrt(s[i].d)/2),0;
	}
	return 0;
}