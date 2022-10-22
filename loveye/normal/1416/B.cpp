#include<cstdio>
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

const int N=1e4+5;
int n,t;
ll a[N];
struct OP {int i,j,x;};
vector<OP> ans;
void work(int i,int j,int x) {
	ans.push_back((OP){i,j,x});
	a[i]-=x*i;
	a[j]+=x*i;
}
int main() {
	cin>>t;
	while(t--) {
		ans.clear();
		cin>>n;
		int sum=0;
		fr(i,1,n) cin>>a[i],sum+=a[i];
		if(sum%n!=0) {
			cout<<-1<<endl;
			continue;
		}
		sum/=n;
		fr(i,2,n) {
			if(a[i]%i) work(1,i,i-a[i]%i);
			work(i,1,a[i]/i);
		}
		fr(i,2,n) work(1,i,sum);
		//fr(i,1,n) cout<<a[i]<<' ';
		//cout<<endl;
		cout<<ans.size()<<endl;
		for(auto x:ans) cout<<x.i<<' '<<x.j<<' '<<x.x<<endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}