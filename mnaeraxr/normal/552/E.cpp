// Template from RLAC

#include <bits/stdc++.h>

#ifdef MARX
	#define DB(a)			clog << __LINE__ << ": " << #a << " = " << (a) << endl
#else
	#define DB(a)
#endif

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main ()
{
	//Improvement region
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//Input region
	#ifdef MARX
		freopen("data.in", "r", stdin);		
		int TIME = clock();
	#endif
	
	string s;
	cin >> s;

	vector<int> dot;

	int n = s.length();
	dot.push_back(0);
	for (int i = 0; i < n; ++i){
		if (s[i] == '*')
		{
			dot.push_back(i - 1);
			dot.push_back(i + 1);
		}
	}
	dot.push_back(n - 1);

	int64 ans = 0;

	// DB("HERE");
	for (int i = 0; i < dot.size(); ++i)
	{
		for (int j = i; j < dot.size(); ++j)
		{
			// DB(dot[i]); dotB(dot[j]);

			stack<int64> val, op;
			for (int k = 0; k < n; ++k){
				// DB(k);
				if (dot[i] == k){
					op.push(-1);
				}

				if ('0' <= s[k] && s[k] <= '9'){
					// DB(s[k]);
					val.push(s[k] - '0');
				}
				else{
					int cur = (s[k] == '*' ? 1 : 0);
					
					while (!op.empty() && op.top() > cur)
					{
						int64 v1 = val.top(); val.pop();
						int64 v2 = val.top(); val.pop();
						// DB("out");
						// DB(v1); DB(op.top()); DB(v2);
						op.pop();
						val.push(v1 * v2);
					}

					// DB(cur);
					op.push(cur);
				}
				if (dot[j] == k){
					while (!op.empty() && op.top() != -1){
						int64 v1 = val.top(); val.pop();
						int64 v2 = val.top(); val.pop();
						int _op = op.top(); op.pop();
						if (_op == 0) val.push(v1 + v2);
						else val.push(v1 * v2);
					}					
					op.pop();
					// DB(")");
				}
			}
			// DB(val.size());
			// DB(op.size());
			while (!op.empty()){
				int64 v1 = val.top(); val.pop();
				int64 v2 = val.top(); val.pop();
				int _op = op.top(); op.pop();
				// DB(v1); DB(v2); DB(_op);

				if (_op == 0) val.push(v1 + v2);
				else val.push(v1 * v2);				
			}
			// DB("OUT");
			ans = max(ans, val.top());

			// exit(0);
		}
	}

	cout << ans << endl;

	//Output region
	#ifdef MARX
		clog << "TIME: " << clock() - TIME << endl;
	#endif

	return 0;
}