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

const int N=1.1e5;
int p[N];
int ll[N],rr[N];
int main(){
	int n=read();
	F(i,1,n)p[i]=read();
	int ans=0;
	int gg=0;
	int cnt=0;
#define add(x) {if((x)>gg){gg=(x);cnt=1;}else if(gg==(x)){cnt++;}}
	F(i,1,n)ll[i]=i>1&&p[i-1]>p[i]?ll[i-1]:i;
	R(i,n,1)rr[i]=i<n&&p[i+1]>p[i]?rr[i+1]:i;
	F(i,1,n){
		add(i-ll[i]);
		add(rr[i]-i);
	}
	F(i,1,n){
		if(i>1&&i<n&&p[i]>p[i-1]&&p[i]>p[i+1]){
			int l=i,r=i;
			while(l>1&&p[l]>p[l-1])l--;
			while(r<n&&p[r]>p[r+1])r++;
			int ld=i-l,rd=r-i;
			int mxd=max(ld,rd),mnd=min(ld,rd);
			if(mxd-mnd==0&&mxd%2==0&&(mxd>gg||(mxd==gg&&cnt==2)))ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}