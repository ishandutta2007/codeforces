#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)2e2 + 10;

int V[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, K; cin >> n >> K;

	for (int i = 0; i < n; ++i){
		cin >> V[i];
	}

	int ans = V[0];

	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= i; ++j)
		{
			int val = 0;
			multiset<int> S1, S2;

			for (int k = 0; k < n; ++k){
				if (k < j || k > i){
					S1.insert(V[k]);
					if ((int)S1.size() > K){
						S1.erase(S1.begin());
					}
				}
				else{
					val += V[k];
					S2.insert(V[k]);
					if ((int)S2.size() > K){
						auto it = S2.end(); --it;
						S2.erase(it);
					}
				}
			}

//			cout << "1>>> " <<  j << " " << i << " " << val << endl;
//			cout << S1.size() << " " << S2.size() << endl;
			ans = max(ans, val);
			if (S1.empty() || S2.empty()) continue;

			auto it1 = S1.end(); --it1;
			auto it2 = S2.begin();

			while (*it1 > *it2){
				val = val + *it1 - *it2;
				if (it1 == S1.begin()) break;
				it1--; it2++;
				if (it2 == S2.end()) break;
			}

//			cout << "2>>> " <<  j << " " << i << " " << val << endl;
			ans = max(ans, val);
		}
	}

	cout << ans << endl;

	return 0;
}