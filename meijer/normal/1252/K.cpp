#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=2e5+1e4;

string t, s, S[MX];
int RA[MX], tRA[MX];
int SA[MX], tSA[MX];
int c[MX], n, m, q;
ll BEG[MX], END[MX];
ll BEG2[MX], END2[MX];

void countingSort(int k) {
	int maxi = max(300, n);
	RE(i,maxi) c[i] = 0;
	RE(i,n) c[i+k<n ? RA[i+k] : 0]++;
	REP(i,1,maxi) c[i] += c[i-1];
	REV(i,0,n) tSA[--c[SA[i]+k<n ? RA[SA[i]+k] : 0]] = SA[i];
	RE(i,n) SA[i]= tSA[i];
}
void constructSA() {
	RE(i,n) RA[i] = t[i];
	RE(i,n) SA[i] = i;
	for(int k=1, r; k<n; k<<=1) {
		countingSort(k);
		countingSort(0);
		tRA[SA[0]] = r = 0;
		REP(i,1,n)
			tRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		RE(i,n)
			RA[i] = tRA[i];
		if(RA[SA[n-1]] == n-1) break;
	}
}
ii stringMatching() {
	int lb=0, ub=n-1;
	while(lb < ub) {
		int mid=(lb+ub)/2;
		if(strncmp(&t[0]+SA[mid], &s[0], m) >= 0)
			ub = mid;
		else
			lb = mid+1;
	}
	if(strncmp(&t[0]+SA[lb], &s[0], m) != 0) return {-1,-1};
	ii ans(lb,0);
	lb=0, ub=n-1;
	while(lb < ub) {
		int mid=(lb+ub)/2;
		if(strncmp(&t[0]+SA[mid], &s[0], m) > 0)
			ub = mid;
		else
			lb = mid+1;
	}
	if(strncmp(&t[0]+SA[lb], &s[0], m) != 0) ub--;
	ans.se = ub;
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t; t.push_back('$'); n=t.size();
    cin>>q;
    RE(i, q) cin>>S[i];

    //begin
    constructSA();
    RE(i,n) BEG[i]=0;
    RE(i,q) {
    	s=S[i]; m=s.size();
    	ii p = stringMatching();
    	if(p.fi == -1) continue;
    	BEG[p.fi]++;
    	BEG[p.se+1]--;
    }
    REP(i,1,n) BEG[i] += BEG[i-1];
    RE(i,n) BEG2[SA[i]] = BEG[i];

    //end
    reverse(t.begin(), --t.end());
    constructSA();
    RE(i,n) END[i]=0;
    RE(i,q) {
    	s=S[i]; m=s.size();
    	reverse(s.begin(), s.end());
    	ii p = stringMatching();
    	if(p.fi == -1) continue;
    	END[p.fi]++;
    	END[p.se+1]--;
    }
    REP(i,1,n) END[i] += END[i-1];
    RE(i,n) END2[n-SA[i]-1] = END[i];

    ll ans=0;
    RE(i,n) ans += BEG2[i]*END2[i];
    cout<<ans<<endl;
}