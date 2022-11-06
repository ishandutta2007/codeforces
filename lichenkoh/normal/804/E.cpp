#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

typedef pair<int,int> pii;
vector<int> perm;
vector<pair<int,int> > solve(int n) {
	perm.resize(n);
  vector<pair<int,int> > v;
  for (int x=0;x<n;x++) for (int y=x+1;y<n;y++) {
    v.PB(MP(x,y));
  }
  do {
    for (int k=0;k<n;k++) perm[k]=k;
    for (auto &w:v) {
      swap(perm[w.fst],perm[w.snd]);
    }
    bool ok=1;
    for (int k=0;k<n;k++) if (perm[k]!=k) {ok=0;break;}
    if (ok) {
      return v;
    }
  } while(next_permutation(v.begin(),v.end()));
  return v;
}

bool check(int n, vector<pii> v) {
	perm.resize(n);
  for (int k=0;k<n;k++) perm[k]=k;
  for (auto &w:v) {
    swap(perm[w.fst],perm[w.snd]);
  }
  bool ok=1;
  for (int k=0;k<n;k++) if (perm[k]!=k) {ok=0;break;}
  return ok;
}

pii head,tail;
map<pii,pii> fwd,bk;
pii norm(pii w) {
	if (w.fst>w.snd) swap(w.fst,w.snd);
	return w;
}
void loopcheck() {
	pii now=head;
	while(now!=tail) {
		now=fwd[now];
	}
}
void insBefore(pii existing, pii fresh) {
	existing=norm(existing); fresh=norm(fresh);
	if (existing==head) {
		head=fresh;
		fwd[fresh]=existing;
		bk[existing]=fresh;
	}
	else {
		pii before=bk[existing];
		fwd[before]=fresh;
		bk[fresh]=before;
		fwd[fresh]=existing;
		bk[existing]=fresh;
	}
	//loopcheck();
}
void insAfter(pii existing, pii fresh) {
	existing=norm(existing); fresh=norm(fresh);
	//printf("insAfter:%d %d %d %d\n",existing.fst,existing.snd,fresh.fst,fresh.snd);
	if (existing==tail) {
		tail=fresh;
		fwd[existing]=fresh;
		bk[fresh]=existing;
	}
	else {
		pii after=fwd[existing];
		fwd[existing]=fresh;
		bk[fresh]=existing;
		fwd[fresh]=after;
		bk[after]=fresh;
	}
	//loopcheck();
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
	if (n==1) {
		printf("YES\n");
		return 0;
	}
	int rem=n%4;
	if (n>=4&&(rem==0||rem==1)) {
		vector<pii> p4=solve(4);
		head=p4[0];
		tail=p4[p4.size()-1];
		for (int i=1;i<p4.size();i++) {
			fwd[p4[i-1]]=p4[i];
			bk[p4[i]]=p4[i-1];
		}
		for (int b=4;b+4<=n;b+=4) {
			for (int x=0;x<b;x+=2) {
				int y=x+1;
				for (int z=b;z<b+4;z++) {
					insBefore(MP(x,y),MP(x,z));
					insAfter(MP(x,y),MP(y,z));
				}
			}
			for (auto &w:p4) {
				insAfter(tail,MP(w.fst+b,w.snd+b));
			}
		}
		if (rem==1) {
			for (int x=0;x<n-1;x+=2) {
				int y=x+1;
				int z=n-1;
				{
					insBefore(MP(x,y),MP(x,z));
					insAfter(MP(x,y),MP(y,z));
				}
			}
		}
		//vector<pii> v;
		printf("YES\n");
		pii now=head;
		//v.PB(now);
		printf("%d %d\n",now.fst+1,now.snd+1);
		while(now!=tail) {
			now=fwd[now];
			//v.PB(now);
			printf("%d %d\n",now.fst+1,now.snd+1);
		}
		//assert(check(n,v));
	}
	else {
		printf("NO\n");
	}
}