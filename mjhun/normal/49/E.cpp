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
#define SZ(x) ((int)x.size())
#define on(x,i) ((x>>i)&1)
#define ws PENAZZI
using namespace std;
typedef long long ll;

char s[64],t[64];
int ns,nt,n;
char a[64],b[64],c[64];
int ws[64][64],wt[64][64];

void doit(char *s, int ws[][64], int ns){
	fore(i,0,ns)ws[i][i+1]=1<<s[i];
	fore(l,2,ns+1)fore(i,0,ns-l+1){
		int j=i+l;
		fore(k,i+1,j)fore(t,0,n)if(on(ws[i][k],b[t])&&on(ws[k][j],c[t])){
			ws[i][j]|=1<<a[t];
		}
	}
}

queue<pair<int,int> > q;
int d[64][64];

int main(){
	scanf("%s%s",s,t);ns=strlen(s);nt=strlen(t);
	fore(i,0,ns)s[i]-='a';
	fore(i,0,nt)t[i]-='a';
	scanf("%d",&n);
	fore(i,0,n){
		char s[8];
		scanf("%s",s);
		a[i]=s[0]-'a';b[i]=s[3]-'a';c[i]=s[4]-'a';
	}
	doit(s,ws,ns);doit(t,wt,nt);
	memset(d,-1,sizeof(d));
	d[0][0]=0;q.push(mp(0,0));
	while(!q.empty()){
		auto p=q.front();q.pop();
		int x=p.fst,y=p.snd;
		fore(i,x+1,ns+1)fore(j,y+1,nt+1)if(d[i][j]<0&&(ws[x][i]&wt[y][j])){
			d[i][j]=d[x][y]+1;
			q.push(mp(i,j));
		}
	}
	printf("%d\n",d[ns][nt]);
	return 0;
}