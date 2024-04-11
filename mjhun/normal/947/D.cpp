#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

char s[100005],t[100005];int ns,nt;
int ss[100005],st[100005];
int zs[100005],zt[100005]; // ultimo 1

void read(char *s, int& n, int *sp, int *z){
	scanf("%s",s);n=strlen(s);
	sp[0]=0;z[0]=-1;
	fore(i,0,n){
		sp[i+1]=sp[i]+(s[i]!='A');
		if(s[i]!='A')z[i+1]=i;
		else z[i+1]=z[i];
	}
}

int main(){
	read(s,ns,ss,zs);read(t,nt,st,zt);
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);a--;c--;
		int x0=ss[b]-ss[a],x1=st[d]-st[c];
		int y0=min(b-a,b-zs[b]-1),y1=min(d-c,d-zt[d]-1);
		//printf("\n %d %d %d %d\n",x0,x1,y0,y1);
		if(!x0&&x1){
			x0+=2;
			y0--;
			while(y0>=y1&&y0%3!=y1%3)y0--;
		}
		if(y0<y1){putchar('0');continue;}
		if(y0%3!=y1%3)x0+=2;
		if(x0>x1||x0%2!=x1%2){
			putchar('0');continue;
		}
		putchar('1');
	}
	puts("");
	return 0;
}