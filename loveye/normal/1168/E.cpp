#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1<<12|5;
int n,a[N],k,p[N],q[N],ip[N],b[N];
void adjust(int i,int j) {
	int t=ip[a[i]^q[i]];
	if(t==i) return;
	if(t==j) return swap(p[i],p[j]),swap(ip[p[i]],ip[p[j]]);
	swap(p[i],p[t]); swap(ip[p[i]],ip[p[t]]);
	swap(q[j],q[t]);
	adjust(t,j);
}
int main() {
	cin>>k; n=1<<k;
	fo(i,0,n) ip[i]=p[i]=q[i]=i,a[i]=0;
	fo(i,0,n) cin>>b[i];
	if(accumulate(b,b+n,0,bit_xor<int>()))
		return cout<<"Fou"<<endl,0;
	fo(i,0,n-1) {
		int x=a[i]^b[i];
		a[i]^=x,a[i+1]^=x;
		adjust(i,i+1);
	}
	cout<<"Shi"<<endl;
	fo(i,0,n) cout<<p[i]<<' ';
	cout<<endl;
	fo(i,0,n) cout<<q[i]<<' ';
	cout<<endl;
	return 0;
}