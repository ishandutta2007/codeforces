#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll EQ=0,LESS=-2,GR=2;
const ll MAXN=1000000+8;
char ans[MAXN];
char ans2[MAXN];
ll g[20],h[20];
ll getnumdig(ll k) {
	ll s=0;
	while(k>0) {
		k/=10;
		s++;
	}
	return s;
}
int main() {
	ios_base::sync_with_stdio(false);
	string s; cin>>s; string t; cin>>t;
	ll n=s.length();
	for (ll d=0;d<10;d++) h[d]=0;
	for (ll i=0;i<n;i++) {
		h[s[i]-'0']++;
	}
	{
		bool sp=(h[0]==1&&h[1]==1);
		for (ll d=2;d<10;d++) sp=sp&&(h[d]==0);
		if (sp) {
			cout<<"0"<<endl;
			return 0;
		}
	}
	for (auto &c:t) {
		h[c-'0']--;
	}
	ll tlen=t.length();
	ll ft=EQ;
	ll ftlead=t[0]-'0';
	{
		ll lead=t[0]-'0';
		for (ll i=1;i<tlen;i++) {
			ll d=t[i]-'0';
			if (d<lead) {ft=LESS; break;}
			if (d>lead) {ft=GR; break;}
		}
	}
	for (ll k=0;k<n;k++) {
		if (n-getnumdig(k)!=k) continue;
		string a=to_string(k);
		if (n-a.length()!=k) continue;
		for (ll d=0;d<10;d++) g[d]=h[d];
		for (auto &c:a) {
			g[c-'0']--;
		}
		bool good=true;
		for (ll d=0;d<10;d++) {
			if (g[d]<0) good=false;
		}
		if (!good) continue;
		ll lead=-1;
		for (ll d=1;d<10;d++) {
			if (g[d]>0) {lead=d; break;}
		}
		bool okk1=(lead!=-1);		
		bool okk2=(t[0]!='0');
		if ((!okk1)&&(!okk2)) continue;
		ll len;
		{
			ll idx=0;
			for (ll i=0;i<tlen;i++) {
				ans2[idx]=t[i];
				idx++;
			}
			for (ll d=0;d<10;d++) {
				for (ll i=0;i<g[d];i++) {
					ans2[idx]=d+'0';
					idx++;
				}
			}
			ans2[idx]='\0';
			len=idx;
		}

		{
			ll idx=0;
			ans[idx]=lead+'0';
			idx++;
			g[lead]--;
			for (ll d=0;d<10;d++) {
				if (d==ftlead && (ft==LESS||ft==EQ)) {
					for (ll i=0;i<tlen;i++) {
						ans[idx]=t[i];
						idx++;
					}
				}
				for (ll i=0;i<g[d];i++) {
					ans[idx]=d+'0';
					idx++;
				}
				if (d==ftlead && (ft==GR)) {
					for (ll i=0;i<tlen;i++) {
						ans[idx]=t[i];
						idx++;
					}
				}
			}
			ans[idx]='\0';
		}
		bool use2=true;
		for (ll i=0;i<len;i++) {
			if (ans2[i]<ans[i]) {
				use2=true; break;
			}
			if (ans2[i]>ans[i]) {
				use2=false; break;
			}
		}
		bool ok1=true,ok2=true;
		if (ans2[0]=='0') ok2=false;
		if (lead==-1) ok1=false;
		if (ok1&&ok2) {
			if (use2)printf("%s\n",ans2);
			else printf("%s\n",ans);
		}
		else if (ok1) {
			printf("%s\n",ans);
		}
		else if (ok2) {
			printf("%s\n",ans2);
		}
		else {
			assert(false);
		}
		return 0;
	}
}