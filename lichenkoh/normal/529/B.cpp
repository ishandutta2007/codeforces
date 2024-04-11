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
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const int mn=1e3+4;
int vw[mn],vh[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&vw[i],&vh[i]);
	}
	int ans=INF;
	for (int H=1;H<=1000;H++) {
		vector<int> v;
		bool ok=true;
		int left=n/2;
		int sumw=0;
		for (int i=0;i<n;i++) {
			int w=vw[i],h=vh[i];
			int orig=-1;
			if (h<=H) {
				orig=w;
			}
			int flip=-1;
			if (w<=H) {
				flip=h;
			}
			if (orig==-1&&flip==-1) {
				ok=false; break;
			}
			else if (orig==-1) {
				left--;
				sumw+=h;
			}
			else if (flip==-1) {
				sumw+=w;
			}
			else {
				sumw+=w;
				int savings=max(0,w-h);
				//if (H==3) printf("i:%d savings:%d\n",i,savings);
				v.PB(savings);
			}
		}
		if (left<0||!ok) continue;
		sort(v.begin(),v.end(),greater<int>());
		for (auto &w:v) {
			if (left<=0) break;
			sumw-=w;
			//if (H==3)printf("minus:%d\n",w);
			left--;
		}
		//if (H==3)printf("sumw:%d\n",sumw);
		chkmin(ans,sumw*H);
	}
	printf("%d\n",ans);
}