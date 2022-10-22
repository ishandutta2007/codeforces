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

const int N=5e4+5;
vector<int> tmp;
vector<pair<int,int> > ans;
void solve(int n,int mt) {
	if(n<=2) {
		fr(i,1,n) tmp.push_back(mt*i);
		return;
	}
	if(!(n&n-1)) return tmp.push_back(mt*n),solve(n-1,mt);
	int p=1<<__lg(n);
	fr(i,p+1,n) {
		ans.push_back(make_pair(i*mt,(2*p-i)*mt));
		tmp.push_back(mt*2*p);
	}
	tmp.push_back(mt*p);
	solve(n-p,mt*2);
	solve(2*p-n-1,mt);
}
int n,T;
int main() {
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--) {
		cin>>n;
		if(n==2) {
			cout<<-1<<endl;
			continue;
		}
		ans.clear(); tmp.clear();
		solve(n,1);
		sort(tmp.begin(),tmp.end());
		int val=tmp.back();
		fo(i,0,tmp.size()) if(tmp[i]==tmp[i+1]) {
			int t=tmp[i];
			assert(t!=val);
			ans.push_back(make_pair(t,t));
			tmp.erase(tmp.begin()+i,tmp.begin()+i+2);
			tmp.push_back(2*t);
			break;
		}
		fo(i,0,tmp.size()) while(tmp[i]^val) {
			ans.push_back(make_pair(tmp[i],0));
			ans.push_back(make_pair(tmp[i],tmp[i]));
			tmp[i]<<=1;
		}
		ans.push_back(make_pair(0,val));
		cout<<ans.size()<<endl;
		for(auto p:ans) cout<<p.first<<' '<<p.second<<endl;
	}
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}