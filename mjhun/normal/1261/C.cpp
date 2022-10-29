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

char _s[1<<20];
int n,m;
vector<vector<int> > x;
vector<vector<int> > s;
vector<vector<int> > x2;
vector<vector<int> > s2;

void psum(vector<vector<int> >& x, vector<vector<int> >& s){
	fore(i,0,n)fore(j,0,m)s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+x[i][j];
}

int get(vector<vector<int> >& s, int i0, int j0, int i1, int j1){
	i0=max(i0,0);j0=max(j0,0);
	i1=min(i1,n);j1=min(j1,m);
	return s[i1][j1]-s[i0][j1]-s[i1][j0]+s[i0][j0];
}

bool can(int t){
	fore(i,0,n)fill(x2[i].begin(),x2[i].end(),0);
	fore(i,t,n-t)fore(j,t,m-t){
		x2[i][j]=get(s,i-t,j-t,i+t+1,j+t+1)==(2*t+1)*(2*t+1);
	}
	psum(x2,s2);
	fore(i,0,n)fore(j,0,m)if(x[i][j]){
		if(!get(s2,i-t,j-t,i+t+1,j+t+1))return false;
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	x.resize(n);
	fore(i,0,n)x[i].resize(m);
	s.resize(n+1);
	fore(i,0,n+1)s[i].resize(m+1);
	x2.resize(n);
	fore(i,0,n)x2[i].resize(m);
	s2.resize(n+1);
	fore(i,0,n+1)s2[i].resize(m+1);
	fore(i,0,n){
		scanf("%s",_s);
		fore(j,0,m)x[i][j]=_s[j]=='X';
	}
	psum(x,s);
	int a=0,b=min(n,m)+5;
	while(b-a>1){
		int c=(a+b)/2;
		if(can(c))a=c;
		else b=c;
	}
	can(a);
	printf("%d\n",a);
	fore(i,0,n){
		fore(j,0,m)putchar(x2[i][j]?'X':'.');
		puts("");
	}
	return 0;
}