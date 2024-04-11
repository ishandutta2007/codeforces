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
const int MAXN = (int)1e6 + 10;
const int64 MOD = (int64)1e9 + 7;

int mnext[MAXN];

void prefix_kmp(string &P){
    int L = SZ(P), p = 0, t = 0;
    for(int i = 1; i < L; i++){
        if(i < p && mnext[i - t] < p - i) mnext[i] = mnext[i - t];
        else{
            int j = max(0,p - i);
            while(i + j < L && P[i + j] == P[j]) ++j;
            mnext[i] = j;
            p = i + j;
            t = i;
        }
    }
}

int64 modexp(int64 v, int p){
	if (p == 0) return 1LL;
	int64 ans = modexp(v * v % MOD, p / 2);
	if (p & 1) ans = ans * v % MOD;
	return ans;
}

bool mk[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
        if (k == 0){
             cout << modexp(26, n) << endl;
             return 0;
        }
	string s; cin >> s;
	prefix_kmp(s);

	bool ok = true;

	int last; cin >> last;
	mk[last] = true;

	for (int i = 1; i < k && ok; ++i){
		int v; cin >> v;
		mk[v] = true;
		int diff = v - last;
		if (diff < SZ(s)){
			if (mnext[diff] + diff != SZ(s)) ok = false;
		}
		last = v;
	}

	if (!ok) cout << 0 << endl;
	else{
		int64 ans = 1;
		for (int i = 1, cnt = 0; i <= n; ++i){
			if (mk[i]) cnt = SZ(s);
			if (!cnt) ans = ans * 26 % MOD;
			cnt--;
			if (cnt < 0) cnt = 0;
		}
		cout << ans << endl;
	}

	return 0;
}