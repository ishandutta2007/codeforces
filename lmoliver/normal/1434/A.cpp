#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int M=6;
const int N=1.1e5;

int a[M];
int b[N];
int t[N];
int main(){
	D(i,M)a[i]=read();
	sort(a,a+M);
	reverse(a,a+M);
	int n=read();
	F(i,1,n)b[i]=read();
	set<pair<int,int> > qaq;
	F(i,1,n)qaq.insert(make_pair(b[i]-a[0],i));
	int ans=INT_MAX;
	while(true){
		pair<int,int> p=*qaq.begin();
		int mn=p.first;
		set<pair<int,int> >::iterator it=qaq.end();
		it--;
		int mx=it->first;
		ans=min(ans,mx-mn);
		int x=p.second;
		qaq.erase(qaq.begin());
		t[x]++;
		if(t[x]==M)break;
		else qaq.insert(make_pair(b[x]-a[t[x]],x));
	}
	printf("%d\n",ans);
	return 0;
}