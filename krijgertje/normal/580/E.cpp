#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN=100000;
const int MAXSEG=1<<19;
const int NHASH=2;
const int H[NHASH]={31,37};
const int M[NHASH]={961748941,982451653};

int slen,nq1,nq2;
char s[MAXLEN+1];

int mult[NHASH][MAXLEN];
int cmult[NHASH][MAXLEN+1];

char slazy[NHASH][MAXSEG];
int sval[NHASH][MAXSEG];

void push(int z,int x,int l,int m,int r) {
	if(slazy[z][x]=='\0') return;
	slazy[z][2*x+1]=slazy[z][x];
	sval[z][2*x+1]=(ll)(cmult[z][m]-cmult[z][l])*(slazy[z][x]-'0')%M[z];
	if(sval[z][2*x+1]<0) sval[z][2*x+1]+=M[z];
	slazy[z][2*x+2]=slazy[z][x];
	sval[z][2*x+2]=(ll)(cmult[z][r]-cmult[z][m])*(slazy[z][x]-'0')%M[z];
	if(sval[z][2*x+2]<0) sval[z][2*x+2]+=M[z];
	slazy[z][x]='\0';
}
void calc(int z,int x) {
	sval[z][x]=(sval[z][2*x+1]+sval[z][2*x+2])%M[z];
}

void init(int z,int x,int l,int r) {
	if(l+1==r) {
		slazy[z][x]=s[l];
		sval[z][x]=(ll)(cmult[z][r]-cmult[z][l])*(s[l]-'0')%M[z];
		if(sval[z][x]<0) sval[z][x]+=M[z];
	} else {
		int m=l+(r-l)/2;
		init(z,2*x+1,l,m);
		init(z,2*x+2,m,r);
		slazy[z][x]='\0';
		calc(z,x);
	}
	//printf("init(%d,%d,%d,%d): %d\n",z,x,l,r,sval[z][x]);
}
void put(int z,int x,int l,int r,int L,int R,char c) {
	if(L<=l&&r<=R) {
		slazy[z][x]=c;
		sval[z][x]=(ll)(cmult[z][r]-cmult[z][l])*(c-'0')%M[z];
		if(sval[z][x]<0) sval[z][x]+=M[z];
	} else {
		int m=l+(r-l)/2;
		push(z,x,l,m,r);
		if(L<m) put(z,2*x+1,l,m,L,R,c);
		if(R>m) put(z,2*x+2,m,r,L,R,c);
		calc(z,x);
	}
}
int get(int z,int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[z][x];
	} else {
		int m=l+(r-l)/2;
		push(z,x,l,m,r);
		int ret=0;
		if(L<m) ret+=get(z,2*x+1,l,m,L,R);
		if(R>m) ret+=get(z,2*x+2,m,r,L,R);
		if(ret>=M[z]) ret-=M[z];
		return ret;
	}
}

void run() {
	scanf("%d%d%d%s",&slen,&nq1,&nq2,s);
	
	REP(i,NHASH) {
		mult[i][0]=1; FOR(j,1,slen) mult[i][j]=(ll)mult[i][j-1]*H[i]%M[i];
		cmult[i][0]=0; REP(j,slen) cmult[i][j+1]=(ll)(cmult[i][j]+mult[i][j])%M[i];
		//REP(j,slen) printf("%d ",mult[i][j]); puts("");
		//REPE(j,slen) printf("%d ",cmult[i][j]); puts("");
		init(i,0,0,slen);
	}

	REP(qi,nq1+nq2) {
		int type; scanf("%d",&type);
		if(type==1) {
			int l,r; char c; scanf("%d%d %c",&l,&r,&c); --l;
			REP(i,NHASH) put(i,0,0,slen,l,r,c);
		}
		if(type==2) {
			int l,r,d; scanf("%d%d%d",&l,&r,&d); --l;
			bool ok=true;
			if(d!=r-l) REP(i,NHASH) {
				int a=mult[i][d],b=get(i,0,0,slen,l,r-d),c=get(i,0,0,slen,l+d,r);
				//printf("\t%d: %d*%d=%d vs %d\n",i,a,b,(ll)a*b%M[i],c);
				if((ll)a*b%M[i]!=c) { ok=false; break; }
			}
			printf("%s\n",ok?"YES":"NO");
		}
	}
}

int main() {
	run();
	return 0;
}