#include<cstdio>
#include<algorithm>
#define MAXN 100000
using namespace std;
int n,p,l,t;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
typedef pair<int,int>pii;
int fr,bk,ans;
pii q[MAXN+10];
void read(){
	Read(l),Read(n),Read(p),Read(t);
}
void solve(){
	q[fr=bk=0]=pii(-t,0);
	int i,l,r;
	for(i=1;i<=n;i++){
		Read(l),Read(r);
		int tdist,tans=0;
		fr--;
		if(fr<0)
			fr=0;
		while(fr<=bk){
			if(q[fr].first+t+p>r)
				break;
			int cnt=(r-max(l,q[fr].first+t))/p;
			int a=q[fr].second+cnt;
			int d=max(l,q[fr].first+t)+cnt*p;
			if(a>tans||(a==tans&&d<tdist))
				tans=a,tdist=d;
			fr++;
		}
		if(ans<tans){
			ans=tans;
			q[++bk]=pii(tdist,tans);
		}
	}
}
int main()
{
	read();
	solve();
	printf("%d\n",ans);
}