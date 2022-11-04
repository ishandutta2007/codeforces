#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9,M=29;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,m,g[M][M],f[1<<21];
char t[N];

bool get(int s,int i) {return s&(1<<i);}

int main() {
	n=read(), m=read();
	scanf("%s",t+1);
	rep(i,1,n-1) g[t[i]-'a'][t[i+1]-'a']++, g[t[i+1]-'a'][t[i]-'a']++;
	int S=(1<<m)-1;
	memset(f,0x3f,sizeof(f)); f[0]=0;
	rep(pop,0,m-1) rep(s,0,S) if(__builtin_popcount(s)==pop) {
		rep(c,0,m-1) if(!get(s,c)) {
			int res=0;
			rep(i,0,m-1) if(i!=c) {
				bool w=get(s,i);
				if(w) res-=g[i][c];
				else res+=g[i][c];
			}
			res=res*(m-pop);
			f[s|(1<<c)]=min(f[s|(1<<c)],res+f[s]);
		}
	}
	printf("%d\n",f[S]);
	return 0;
}