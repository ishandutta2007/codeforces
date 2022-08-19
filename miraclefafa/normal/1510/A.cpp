#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef vector<string> output;
string s;

void extendL(output &a,int width) {
	string s(width,' ');
	rep(i,0,SZ(a)) a[i]=s+a[i];
}

void extendR(output &a,int width) {
	string s(width,' ');
	rep(i,0,SZ(a)) a[i]+=s;
}

void extendD(output &a,int ht) {
	string s(a.empty()?0:SZ(a[0]),' ');
	rep(i,0,ht) a.pb(s);
}
void extendU(output &a,int ht) {
	reverse(all(a));
	string s(a.empty()?0:SZ(a[0]),' ');
	rep(i,0,ht) a.pb(s);
	reverse(all(a));
}

void ofill(output &a,int x,int y,string s) {
	assert(x>=0&&x<SZ(a)&&y>=0&&y+SZ(s)<=SZ(a[0]));
	for (int i=0;i<SZ(s);i++) a[x][y+i]=s[i];
}

void vfill(output &a,int x,int y,string s) {
	assert(x>=0&&x+SZ(s)<=SZ(a)&&y>=0&&y<=SZ(a[0]));
	for (int i=0;i<SZ(s);i++) if (a[x+i][y]==' ')
		a[x+i][y]=s[i];
}

void debug(output s) {
	int h=SZ(s),w=SZ(s[0]);
	rep(i,0,h) assert(SZ(s[i])==w);
	/*puts("DEBUG start  *********");
	rep(i,0,h) {
		printf("%s\n",s[i].c_str());
	}
	puts("DEBUG finish *********");
	puts("");
	puts("");*/
}
output parseterm(string s);
output parseexpr(string s) {
	VI orb;
	int od=0;
	rep(i,0,SZ(s)) {
		if (s[i]=='(') od++;
		else if (s[i]==')') od--;
		if (od==0&&s[i]=='|') orb.pb(i);
	}
	if (orb.empty()) return parseterm(s);
	vector<output> fs;
	int pre=0;
	orb.pb(SZ(s));
	for (int i=0;i<SZ(orb);i++) {
		fs.pb(parseterm(s.substr(pre,orb[i]-pre)));
		pre=orb[i]+1;
	}
	int mxd=0;
	for (auto &x:fs) mxd=max(mxd,SZ(x[0]));
	for (auto &x:fs) {
		int od=SZ(x[0]);
		extendR(x,mxd-od);
		ofill(x,1,od,string(mxd-od,'-'));
		//for (int j=od;j<mxd;j++) x[1][j]='-';
		extendR(x,3);
		ofill(x,1,SZ(x[0])-3,"->+");
		extendL(x,3);
		ofill(x,1,0,"+->");
	}
	output w;
	int lsp=0;
	rep(i,0,SZ(fs)) {
		if (i!=0) extendD(w,1),lsp=SZ(w);
		for (auto x:fs[i]) w.pb(x);
	}
	vfill(w,2,0,string(lsp-1,'|'));
	vfill(w,2,SZ(w[0])-1,string(lsp-1,'|'));
	debug(w);
	return w;
}

output gensingletter(string s) {
	assert(SZ(s)==1);
	output t;
	t.pb(string(1,s[0]));
	return t;
}

bool issingle(output &a) {
	return SZ(a)==1&&SZ(a[0])==1;
}

output genletter(string s) {
	output t;
	int n=SZ(s);
	t.pb("+"+string(n+2,'-')+"+");
	t.pb("+ "+s+" +");
	t.pb("+"+string(n+2,'-')+"+");
	debug(t);
	return t;
}

output genplus(output s) {
	output t=s;
	extendR(t,3);
	ofill(t,1,SZ(t[0])-3,"->+");
	extendL(t,3);
	ofill(t,1,0,"+->");
	extendD(t,2);
	ofill(t,SZ(t)-1,0,"+<"+string(SZ(t[0])-3,'-')+"+");
	vfill(t,2,0,string(SZ(t)-3,'|'));
	vfill(t,2,SZ(t[0])-1,string(SZ(t)-3,'|'));
	debug(t);
	return t;
}

output genques(output s) {
	output t=s;
	extendR(t,3);
	ofill(t,1,SZ(t[0])-3,"->+");
	extendL(t,3);
	ofill(t,1,0,"+->");
	extendU(t,2);
	ofill(t,0,0,"+"+string(SZ(t[0])-3,'-')+">+");
	vfill(t,1,0,string(2,'|'));
	vfill(t,1,SZ(t[0])-1,string(2,'|'));
	extendU(t,1);
	debug(t);
	return t;
}

output genstar(output s) {
	output t=s;
	extendR(t,3);
	ofill(t,1,SZ(t[0])-3,"->+");
	extendL(t,3);
	ofill(t,1,0,"+->");
	extendU(t,2);
	ofill(t,0,0,"+"+string(SZ(t[0])-3,'-')+">+");
	extendD(t,2);
	ofill(t,SZ(t)-1,0,"+<"+string(SZ(t[0])-3,'-')+"+");	
	debug(t);
	vfill(t,1,0,string(SZ(t)-2,'|'));
	vfill(t,1,SZ(t[0])-1,string(SZ(t)-2,'|'));
	extendU(t,1);
	debug(t);
	return t;
}

void concat(output &a,output b) {
	if (a.empty()) { a=b; return; }
	int ca=SZ(a),cb=SZ(b);
	if (ca<cb) extendD(a,cb-ca);
	else extendD(b,ca-cb);
	ca=max(ca,cb);
	extendR(a,2);
	ofill(a,1,SZ(a[0])-2,"->");
	rep(i,0,ca) a[i]+=b[i];
	debug(a);
}
output parseterm(string s) {
	vector<string> blk;
	//string curs="";
	rep(i,0,SZ(s)) {
		if (s[i]>='A'&&s[i]<='Z') {
			blk.pb(string(1,s[i]));
		} else {
			//if (!curs.empty()) blk.pb(curs);
			//curs="";
			if (s[i]=='(') {
				int od=1,j=i+1;
				while (j<SZ(s)) {
					if (s[j]=='(') od++;
					else if (s[j]==')') od--;
					if (od==0) {
						blk.pb(s.substr(i,j-i+1));
						break;
					}
					j++;
				}
				i=j;
			} else blk.pb(string(1,s[i]));
		}
	}
	//if (!curs.empty()) blk.pb(curs);
	vector<output> outs;
	for (auto x:blk) {
		if (x[0]>='A'&&x[0]<='Z') {
			outs.pb(gensingletter(x));
		} else if (x[0]=='(') {
			outs.pb(parseexpr(x.substr(1,SZ(x)-2)));
		} else {
			assert(!outs.empty());
			auto y=outs.back();
			if (issingle(y)) y=genletter(y[0]);
			outs.pop_back();
			if (x[0]=='+') outs.pb(genplus(y));
			else if (x[0]=='?') outs.pb(genques(y));
			else if (x[0]=='*') outs.pb(genstar(y));
		}
	}
	output f;
	rep(i,0,SZ(outs)) {
		if (!issingle(outs[i])) {
			concat(f,outs[i]);
		} else {
			string st;
			int j=i;
			while (j<SZ(outs)&&issingle(outs[j])) {
				st+=outs[j][0];
				j+=1;
			}
			concat(f,genletter(st));
			i=j-1;
		}
	}
	debug(f);
	return f;
}

int main() {
	cin>>s;
	auto ans=parseexpr(s);
	extendR(ans,3);
	ofill(ans,1,SZ(ans[0])-3,"->F");
	extendL(ans,3);
	ofill(ans,1,0,"S->");
	printf("%d %d\n",SZ(ans),SZ(ans[0]));
	for (auto x:ans) printf("%s\n",x.c_str());
}