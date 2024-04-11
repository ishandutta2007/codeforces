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
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

char s[1024],s0[64],s1[64];int n,n0,n1;
int a0[64][32];
int a1[64][32];

void doit(char* s, int& n, int a[][32]){
	n=strlen(s);
	int b[64];
	b[0]=-1;
	fore(i,0,n){
		int k=b[i];
		while(k>=0&&s[k]!=s[i])k=b[k];
		b[i+1]=k+1;
	}
	if(n>1)a[0][s[0]-'a']=1;
	fore(i,1,n){
		fore(j,0,26){
			if(j==s[i]-'a'){
				a[i][j]=i+1;
				if(a[i][j]==n)a[i][j]=b[n];
			}
			else a[i][j]=a[b[i]][j];
		}
	}
}

#define INF (1<<20)

int f[64][64];
int f2[64][64];

int main(){
	scanf("%s%s%s",s,s0,s1);
	n=strlen(s);
	doit(s0,n0,a0);
	doit(s1,n1,a1);
	fore(x,0,n0)fore(y,0,n1)f[x][y]=-INF;
	f[0][0]=0;
	fore(i,0,n){
		fore(x,0,n0)fore(y,0,n1)f2[x][y]=-INF;
		fore(x,0,n0)fore(y,0,n1){
			fore(j,0,26)if(s[i]=='*'||s[i]=='a'+j){
				int m0=x==n0-1&&s0[x]=='a'+j;
				int m1=y==n1-1&&s1[y]=='a'+j;
				int xx=a0[x][j];
				int yy=a1[y][j];
				f2[xx][yy]=max(f2[xx][yy],f[x][y]+m0-m1);
			}
		}
		mcpy(f,f2);
	}
	int r=-INF;
	fore(x,0,n0)fore(y,0,n1)r=max(r,f[x][y]);
	printf("%d\n",r);
	return 0;
}