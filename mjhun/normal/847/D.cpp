#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int MXN=2e5+1;
ll N, T, A[MXN];
bool cnt[MXN];

int main(){ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> T;
	priority_queue<ii> pq;
	fore(x,0,N){
		cin>>A[x];
		A[x]=max(0LL, A[x]-(x+1LL));
		pq.push({-A[x],x});
	}
	int ans=0, tmp=0, i=N-1;

	while(!pq.empty()){
		ii tmpP=pq.top(); pq.pop();
		while(i>=0 && i+1-tmpP.first>=T)tmp-=cnt[i],i--;
		if(tmpP.second<=i)
			cnt[tmpP.second]=1,tmp++;
		ans=max(ans,tmp);
	}
	cout << ans << "\n";
	return 0;
}