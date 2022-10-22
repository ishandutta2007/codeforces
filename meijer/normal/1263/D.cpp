#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=3e5, MOD=1e9+7, CHRS='z'-'a'+1;

int n;
string s[MX];
int r[CHRS], p[CHRS], sets=0;
set<char> exist;

void buildDSU() {
	RE(i,CHRS) r[i]=0, p[i]=i;
}
int getSet(int i) {return p[i]==i ? i : p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
	if(!isSameSet(i,j)) {
		sets--;
		i = getSet(i); j=getSet(j);
		if(r[i] > r[j]) {
			p[j] = i;
		} else {
			p[i] = j;
			if(r[i] == r[j]) r[j]++;
		}
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n)
    	cin>>s[i];
    buildDSU();
    RE(i,n) for(char c:s[i]) {
    	if(exist.count(c)) continue;
    	exist.insert(c);
    	sets++;
    }
    RE(i,n) for(char c:s[i]) for(char d:s[i]) {
    	unionSet(c-'a', d-'a');
    }
    cout<<sets<<endl;
}