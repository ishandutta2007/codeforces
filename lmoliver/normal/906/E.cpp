#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=5.1e5;
const int C=26;
const int S=2*N;

namespace PAM{

struct Node{
	int ch[C],fa;
	int len;
	int d;
	int sf;
	int sv;
	int sid;
}o[S];
int nid;
int ot,et;
void init(){
	nid=0;
	ot=++nid;
	o[ot].len=-1;
	et=++nid;
	o[et].len=0;
	o[et].fa=ot;
}

int dp[S];
int lf[S];

void build(int a[],int n){
	init();
	int l=ot;
	D(i,n){
		// cerr<<"l="<<l<<endl;
		// cerr<<"#"<<i<<endl;
		// cerr<<"a="<<a[i]<<endl;
		while(i-o[l].len-1<0||a[i-o[l].len-1]!=a[i])l=o[l].fa;
		// cerr<<":"<<__LINE__<<" l="<<l<<endl;
		if(o[l].ch[a[i]])l=o[l].ch[a[i]];
		else{
			// cerr<<":"<<__LINE__<<" l="<<l<<endl;
			int x=++nid;
			o[l].ch[a[i]]=x;
			o[x].len=o[l].len+2;
			if(l!=ot){
				l=o[l].fa;
				while(i-o[l].len-1<0||a[i-o[l].len-1]!=a[i])l=o[l].fa;
				assert(o[l].ch[a[i]]);
				l=o[l].ch[a[i]];
			}
			else{
				l=et;
			}
			o[x].fa=l;
			o[x].d=o[x].len-o[l].len;
			o[x].sf=o[l].len>0&&o[x].d==o[l].d?o[l].sf:l;
			l=x;
		}
		// cerr<<"l="<<l<<" fa[l]="<<o[l].fa<<endl;
		dp[i]=INT_MAX>>1;
		if(i>=1&&a[i]==a[i-1]){
			dp[i]=i<=1?0:dp[i-2];
			lf[i]=i-2;
		}
		for(int p=l;p!=et;p=o[p].sf){
			// cerr<<o[o[p].sf].len<<" - "<<o[p].len<<endl;
			int f=o[p].fa;
			int sv=f==o[p].sf?INT_MAX>>1:o[f].sv;
			int sid=i-(o[o[p].sf].len+o[p].d);
			int dsid=sid==-1?0:dp[sid];
			if(dsid<=sv){
				o[p].sv=dsid;
				o[p].sid=sid;
			}
			else{
				o[p].sv=o[f].sv;
				o[p].sid=o[f].sid;
			}
			if(o[p].sv+1<dp[i]){
				dp[i]=o[p].sv+1;
				lf[i]=o[p].sid;
			}
		}
		if(!(i&1))dp[i]=INT_MAX>>1;
		// cerr<<"dp="<<dp[i]<<endl;
	}
}

}

int n;
char s[N],t[N];
int a[S];

int main(){
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);
	D(i,n)a[2*i]=s[i]-'a';
	D(i,n)a[2*i+1]=t[i]-'a';
	PAM::build(a,2*n);
	int ans=PAM::dp[2*n-1];
	if(ans>=(int)1e9){
		puts("-1");
		exit(0);
	}
	printf("%d\n",ans);
	int x=2*n-1;
	while(x>=0){
		int l=PAM::lf[x];
		if(x-l>2)printf("%d %d\n",(l+3)>>1,(x+1)>>1);
		x=l;
	}
	return 0;
}