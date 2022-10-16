#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int maxn = 100000;
const int oo = 0x3f3f3f3f;
const double pi = acos(-1);
const double eps = 1e-7;

int gcd(int a, int b){
	if (!a) return b;
	if (!b) return a;
	return __gcd(a, b);
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if (n < 5){
    	cout << "YES" << endl;
    	return 0;
    }

    vector<pii> V(n);

    for (int i = 0; i < n; ++i)
    	cin >> V[i].first >> V[i].second;

    random_shuffle(V.begin(), V.end());

    map<pii, int> M;
    vector<vi> A;
    int x = V[0].first;
    int y = V[0].second;
    int cnt = 0;

    for (int i = 1; i < n; ++i){
    	int g = gcd(V[i].first - x, V[i].second - y);
    	pii p = {(V[i].first - x) / g, (V[i].second - y) / g};
    	if (!M.count(p)){
    		M[p] = cnt++;
    		A.push_back(vi());
    	}
    	A[M[p]].push_back(i);
    }

    for (int i = 0; i < cnt && 1. * clock() < 1.7 * CLOCKS_PER_SEC; ++i){
    	bool s = false;
    	int g = -1;
    	pii p = {0, 0};
    	bool f = false;
    	bool ok = true;
    	for (int j = 0; j < cnt && ok; ++j){
    		if (i == j) continue;
    		for (auto k : A[j]){
				if (!f){
					x = V[k].first;
					y = V[k].second;
					f = true;
				}
				else if (!s){
					g = gcd(V[k].first - x, V[k].second - y);
					p = {(V[k].first - x) / g, (V[k].second - y) / g};
					s = true;
				}
				else{
					int gg = gcd(V[k].first - x, V[k].second - y);
					pii pp = {(V[k].first - x) / gg, (V[k].second - y) / gg};
					if (p != pp){
						ok = false;
						break;
					}
				}
    		}
    	}
    	if (ok){
    		cout << "YES" << endl;
    		return 0;
    	}
    }

    cout << "NO" << endl;
	
	return 0;
}