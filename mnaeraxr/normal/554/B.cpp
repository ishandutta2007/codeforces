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

	int n; cin >> n;
	map<string,int> M;
	int ans = 0;
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		ans = max(ans, ++M[s]);
	}
	cout << ans << endl;

	//Output region
	#ifdef MARX
		clog << "TIME: " << clock() - TIME << endl;
	#endif

	return 0;
}