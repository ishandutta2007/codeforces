#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;
const int BITS = 30;

int st[maxn];

int get(int B, int E, int v){
	if (B == E) return 0;

	int c = 0;

	for (int i = BITS - 1; ~i; --i){
		int d = c | (1 << i);

		int p = lower_bound(st + B, st + E, d) - st;
		int b = v >> i & 1;

		if (b){
			if (p > B)
				E = p;
			else
				B = p, c = d;
		}
		else{
			if (p < E)
				B = p, c = d;
			else
				E = p;
		}
	}

	assert(c == st[B]);

	return v ^ c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> v(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> v[i];

    int B = maxn, answer = 0;

    for (int i = n; i; --i){
    	int E = upper_bound(st + B, st + maxn, v[i]) - st;
    	if (E < maxn) ++E;

    	int curAnswer = get(B, E, v[i]);
    	answer = max(answer, curAnswer);

    	while (B < maxn && st[B] < v[i])
    		B++;

    	st[--B] = v[i];
    }

    cout << answer << endl;

    return 0;
}