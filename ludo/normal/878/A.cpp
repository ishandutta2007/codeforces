#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define all(v) (v).begin(), (v).end()
#define rs resize

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

// lambda-expression: [] (args) -> retType { body }

#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const bool LOG = false;
void Log() {
	if(LOG) cerr << "\n\n";
}
template<class T, class... S>
void Log(T t, S... s) {
	if(LOG) cerr << t << "\t", Log(s...);
}

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

int values[11];
bool ison[10][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	values[10] = 0;
	for (int i = 0; i < 10; i++)
		values[i] = 1 << i;

	int N;
	cin >> N;
	rep(i, 0, N) {
		char op; int xi;
		cin >> op >> xi;
		if (op == '&') rep(j, 0, 11) values[j] &= xi;
		if (op == '^') rep(j, 0, 11) values[j] ^= xi;
		if (op == '|') rep(j, 0, 11) values[j] |= xi;
	}

	for (int i = 0; i < 10; i++) {
		ison[i][0] = (values[10] >> i) & 1;
		ison[i][1] = (values[i] >> i) & 1;
	}

	int valxor = 0, valor = 0, valand = 1023;
	for (int i = 0; i < 10; i++) {
		if (ison[i][0] && ison[i][1])
			valor |= 1 << i;
		else if (!ison[i][0] && !ison[i][1])
			valand &= ~(1 << i);
		else if (ison[i][0] && !ison[i][1])
			valxor |= 1 << i;
	}
	cout << 3 << endl;
	cout << "^ " << valxor << endl;
	cout << "| " << valor << endl;
	cout << "& " << valand << endl;
	return 0;
}