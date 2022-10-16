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
const int MAXN = (int)1e5 + 10;

priority_queue<int> PQ1, PQ2;

void insert(int v){
	if (PQ1.empty()) PQ1.push(v);
	else{
		if (v <= PQ1.top())
			PQ1.push(v);
		else
			PQ2.push(-v);

		while (PQ1.size() > PQ2.size() + 1){
			int cur = PQ1.top(); PQ1.pop();
			PQ2.push(-cur);
		}
		while (PQ2.size() > PQ1.size()){
			int cur = -PQ2.top(); PQ2.pop();
			PQ1.push(cur);
		}
	}
}

void end(){
	cout << -1 << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, p, x, y;
	cin >> n >> k >> p >> x >> y;

	int sum = 0;

	for (int i = 0; i < k; ++i){
		int v; cin >> v;
		insert(v);
		sum += v;
	}

	if (sum + n - k > x)
		end();

	vector<int> ans(n - k);

	for (int i = k; i < n && sum <= x; ++i){
		if (PQ1.empty() || PQ1.top() < y){
			insert(y);
			sum += y;
			ans[i - k] = y;
		}
		else{
			sum += 1;
			insert(1);
			ans[i - k] = 1;
		}
	}

	if (sum <= x && PQ1.top() >= y){
		for (auto i : ans) cout << i << " ";
		cout << endl;
	}
	else{
		end();
	}

	return 0;
}