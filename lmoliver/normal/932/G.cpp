#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int MOD=1e9+7;
int add(int a,int b){return a+b<MOD?a+b:a+b-MOD;}
void dadd(int &a,int b){a=add(a,b);}

const int N=1.1e6;
const int C=26;

namespace PAM{

struct Node{
	int fa,ch[C];
	int len;
	int d,sf;
	int sans;
}o[N];

int ns=0;
int ert=++ns;
int ort=++ns;
int last;

int ans[N];
void solve(const char *s){
	o[ert].fa=ort;
	o[ort].len=-1;
	last=ort;

	ans[0]=1;
	int i;
	for(i=0;s[i];i++){
		int c=s[i]-'a';
		int l=last;
		while(l&&(o[l].len==i||s[i-o[l].len-1]!=s[i]))l=o[l].fa;
		// if(!l)last=rt;
		if(o[l].ch[c])last=o[l].ch[c];
		else{
			o[l].ch[c]=++ns;
			o[ns].len=o[l].len+2;
			l=o[l].fa;
			while(l&&(o[l].len==i||s[i-o[l].len-1]!=s[i]))l=o[l].fa;
			int f=o[l].ch[c];
			if(!f)f=ert;
			o[ns].fa=f;
			last=ns;
			o[ns].d=o[ns].len-o[f].len;
			o[ns].sf=o[ns].d==o[f].d?o[f].sf:f;
		}
		int &a=ans[i+1];
		a=0;
#ifdef DEBUG
		for(int l=last;o[l].len>0;l=o[l].fa)if(i%2==1)dadd(a,ans[i+1-o[l].len]);
#else
		// cerr<<"i="<<i<<endl;
		for(int l=last;o[l].len>0;l=o[l].sf){
			// cerr<<"("<<o[l].sf<<","<<l<<"]"<<endl;
			o[l].sans=ans[i+1-(o[o[l].sf].len+o[l].d)];
			if(o[l].sf!=o[l].fa){
				// cerr<<"l="<<l<<" fa="<<o[l].fa<<endl;
				// cerr<<"+"<<o[o[l].fa].sans<<endl;
				dadd(o[l].sans,o[o[l].fa].sans);
			}
			// cerr<<"sans["<<l<<"]="<<o[l].sans<<endl;
			if(i%2==1)dadd(a,o[l].sans);
		}
		// cerr<<"str="<<string(s+i-o[last].len+1,s+i+1)<<" ans="<<a<<endl;
#endif
	}
	printf("%d\n",ans[i]);
}

}

char in[N];
char s[N];
int main(){
	scanf("%s",in);
	int n=strlen(in);
	D(i,n>>1){
		s[i*2]=in[i];
		s[i*2+1]=in[n-1-i];
	}
	// cerr<<s<<endl;
	PAM::solve(s);
	return 0;
}