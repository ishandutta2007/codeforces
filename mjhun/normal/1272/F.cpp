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

char s[256],t[256];
int n,m;
bool v[512][256][256];pair<int,pair<int,int> > c[512][256][256];
queue<pair<int,pair<int,int> > > q;
string r="";

int main(){
	scanf("%s%s",s,t);n=strlen(s);m=strlen(t);
	q.push(mp(0,mp(0,0)));
	v[0][0][0]=true;
	while(!v[0][n][m]){
		auto p=q.front();q.pop();
		int d=p.fst,i=p.snd.fst,j=p.snd.snd;
		if(d+1<512){
			int ii=i,jj=j;
			if(s[i]=='(')ii++;
			if(t[j]=='(')jj++;
			if(!v[d+1][ii][jj]){
				v[d+1][ii][jj]=true;
				c[d+1][ii][jj]=mp(d,mp(i,j));
				q.push(mp(d+1,mp(ii,jj)));
			}
		}
		if(d>0){
			int ii=i,jj=j;
			if(s[i]==')')ii++;
			if(t[j]==')')jj++;
			if(!v[d-1][ii][jj]){
				v[d-1][ii][jj]=true;
				c[d-1][ii][jj]=mp(d,mp(i,j));
				q.push(mp(d-1,mp(ii,jj)));
			}
		}
	}
	int d=0,i=n,j=m;
	while(d||i||j){
		assert(v[d][i][j]);
		auto p=c[d][i][j];
		if(p.fst<d)r.pb('(');
		else r.pb(')');
		d=p.fst;i=p.snd.fst;j=p.snd.snd;
	}
	reverse(r.begin(),r.end());
	puts(r.c_str());
	return 0;
}