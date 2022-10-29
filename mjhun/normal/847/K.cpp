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

ll N, A, B, K, F;
int id_cnt=0;
map<string,int> id;
map<pair<int,int>, ll> val;

int main(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> A >> B >> K >> F;
	int last=-1;
	fore(x,0,N){
		string s[2];
		fore(y,0,2){
			cin >> s[y];
			if(!id.count(s[y]))id[s[y]]=id_cnt++;
		}
		int u=id[s[0]], v=id[s[1]];
		val[{min(u,v),max(u,v)}]+= last==id[s[0]] ? B : A;
		last = id[s[1]];
	}

	priority_queue<pair<ll,pair<int,int> > > pq;
	for(auto p : val)
		pq.push({p.second,p.first});

	ll ans=0;
	while(!pq.empty()){
		if(K){
			if(pq.top().first>F){
				ans += F; pq.pop(); K--;
			}else{
				ans += pq.top().first; pq.pop();
			}
		}else{
			ans += pq.top().first; pq.pop();
		}
	}

	cout << ans << "\n";
	return 0;
}