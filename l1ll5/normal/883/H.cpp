#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=4e5+11;
char s[N],rf[N];
int a[30],b[30],g[30];
int c[99],d[99],tc;
int tt;
void print(int xxx){
	rep(i,1,tc)
		rep(j,1,d[i])
			putchar(c[i]);
	if(xxx){
		putchar(rf[1]);
	}
	per(i,1,tc)
		rep(j,1,d[i])
			putchar(c[i]);
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	int n;
	scanf("%d%s",&n,s);
	for(char*c=s;*c;c++){
		if(*c>='a'&&*c<='z'){
			a[*c-'a']++;
		}else if(*c>='A'&&*c<='Z')b[*c-'A']++;
		else g[*c-'0']++;
	}
	rep(i,0,25){
		if(a[i]>1) {
			c[++tc]=i+'a';
			d[tc]=a[i]/2;
			a[i]%=2;
		}
		if(b[i]>1){
			c[++tc]=i+'A';
			d[tc]=b[i]/2;
			b[i]%=2;
		}
	}
	rep(i,0,9)if(g[i]>1){
		c[++tc]=i+'0';
		d[tc]=g[i]/2;
		g[i]%=2;
	}
	int th=0;
	rep(i,0,25)if(a[i])rf[++th]=i+'a';//th++;
	rep(i,0,25)if(b[i])rf[++th]=i+'A';
	rep(i,0,9)if(g[i])rf[++th]=i+'0';
//	putchar(rf[1]),putchar(rf[2]);
	if(th<=1)return puts("1"),print(th),0;
	rep(R,th,n){
		if(n%R==0){
			int t=n/R;
			if(t%2){
				printf("%d\n",R);
				if(th<R){
					int cnt=1;
					rep(i,1,(R-th)/2){
						if(!d[cnt])cnt++;
						rf[++th]=c[cnt];
						rf[++th]=c[cnt];
						d[cnt]--;
					}
				}
				rep(I,1,R){
					static char r[N];
					rep(i,1,t/2){
						if(!d[tc])tc--;
						r[i]=c[tc];
						d[tc]--;
					}
					rep(i,1,t/2)
						putchar(r[i]);
//					cout << "f1";
					putchar(rf[I]);
//					cout << "f2";
					per(i,1,t/2)
						putchar(r[i]);
					if(I!=R)putchar(' ');
				}
				
				
				return 0;
			}
		}
	}
}