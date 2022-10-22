#include <bits/stdc++.h>
using namespace std;

//macros
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int t, n;
string a, b;
int cntA[2][2];
int cntB[2][2];
vi ans;
int lastRev=-1;

void rev(int i) {
	if(i == 0) return;
	ans.pb(i);
	reverse(a.begin(), a.begin()+i);
}

void program() {
	cin>>t;
	while(t--) {
		cin>>a>>b;
		n=a.size();
		RE(i,n) a[i]-='0';
		RE(i,n) b[i]-='0';
		RE(i,2) RE(j,2) cntA[i][j]=cntB[i][j]=0;
		RE(i,n/2) cntA[a[i*2]][a[i*2+1]]++;
		RE(i,n/2) cntB[b[i*2]][b[i*2+1]]++;
		bool pos=1;
		if(cntA[0][0] != cntB[0][0]) pos=0;
		if(cntA[1][1] != cntB[1][1]) pos=0;
		if(cntA[0][1]+cntA[1][0] != cntB[0][1]+cntB[1][0]) pos=0;
		if(!pos) {
			cout<<-1<<endl;
			continue;
		}

		ans.clear();
		pos = 0;
		lastRev = -1;
		if(cntA[0][1] != cntB[1][0]) {
			RE(i,n/2) {
				bool f=a[i*2], s=a[i*2+1];
				if(f == s) continue;
				cntA[f][s]--;
				cntA[s][f]++;
				if(cntA[0][1] == cntB[1][0]) {
					rev(i*2+2);
					pos = 1;
					break;
				}
			}
		} else pos = 1;
		if(!pos) {
			RE(i,n/2) {
				bool f=a[i*2], s=a[i*2+1];
				if(f == s) continue;
				cntA[f][s]++;
				cntA[s][f]--;
			}

			RE(i,n/2) {
				bool f=b[i*2], s=b[i*2+1];
				if(f == s) continue;
				cntB[f][s]--;
				cntB[s][f]++;
				if(cntA[0][1] == cntB[1][0]) {
					lastRev = i*2+2;
					reverse(b.begin(), b.begin()+lastRev);
					break;
				}
			}
		}
		RE(i,n/2) {
			for(int j=i*2; j<n; j+=2) {
				if(a[j] == b[n-i*2-1] && a[j+1] == b[n-i*2-2]) {
					rev(j);
					rev(j+2);
					break;
				}
			}
		}
		if(lastRev != -1) ans.pb(lastRev);
		cout<<ans.size()<<endl;
		RE(i,ans.size()) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
	}
}