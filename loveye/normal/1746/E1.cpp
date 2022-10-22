#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

int n;
void query(vector<int> A,vector<int> B) {
	cout<<"? "<<A.size()+B.size()<<' ';
	fo(i,0,A.size()) cout<<A[i]<<' ';
	fo(i,0,B.size()) cout<<B[i]<<' ';
	cout<<endl;
}
vector<int> merge(vector<int> a,vector<int> b,vector<int> c) {
	vector<int> d=a;
	fo(i,0,b.size()) d.push_back(b[i]);
	fo(i,0,c.size()) d.push_back(c[i]);
	return d;
}
int ret() {
	string s; cin>>s;
	return s[0]=='Y';
}
void work(int u,vector<int> a) {
	cout<<"! "<<a[u]<<endl;
	string s; cin>>s;
	if(s[1]=='(') {
		cout<<"? 1 "<<a[(u+1)%3]<<endl;
		cout<<"! "<<a[(u+1+!ret())%3]<<endl;
	}
}
void solve(vector<int> a) {
	if(a.size()==1) {
		cout<<"! "<<a[0]<<endl;
		return;
	}
	if(a.size()==2) {
		cout<<"! "<<a[0]<<endl;
		string s; cin>>s;
		if(s[1]=='(') cout<<"! "<<a[1]<<endl;
		return;
	}
	if(a.size()==3) {
		cout<<"? 1 "<<a[0]<<endl;
		if(ret()) return work(0,a);
		cout<<"? 1 "<<a[0]<<endl;
		if(ret()) return work(0,a);
		cout<<"? 1 "<<a[1]<<endl;
		if(ret()) return work(1,a);
		cout<<"? 1 "<<a[1]<<endl;
		if(ret()) return work(1,a);
		cout<<"? 1 "<<a[2]<<endl;
		if(ret()) return work(2,a);
		cout<<"? 1 "<<a[2]<<endl;
		if(ret()) return work(2,a);
	}
	int lim=max(int(a.size())/4,1);
	vector<int> A,B,C,D;
	int len[4]={lim,lim,lim,lim};
	if(a.size()==3) --len[3];
	else fr(i,1,a.size()%4) ++len[4-i];
	fo(i,0,len[0]) A.push_back(a[i]);
	fo(i,len[0],len[0]+len[1]) B.push_back(a[i]);
	fo(i,len[0]+len[1],len[0]+len[1]+len[2]) C.push_back(a[i]);
	fo(i,len[0]+len[1]+len[2],a.size()) D.push_back(a[i]);
	string s; int b0,b1;
	query(A,B); b0=ret();
	query(A,C); b1=ret();
	if(b0&&b1) solve(merge(A,B,C));
	if(b0&&!b1) solve(merge(A,B,D));
	if(!b0&&b1) solve(merge(A,C,D));
	if(!b0&&!b1) solve(merge(B,C,D));
}
int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	vector<int> a(n);
	fo(i,0,n) a[i]=i+1;
	solve(a);
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}