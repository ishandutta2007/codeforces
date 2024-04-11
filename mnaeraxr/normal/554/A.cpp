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

	set<string> S;
	for (int i = 0; i <= s.length(); ++i){
		for (int j = 0; j < 26; ++j){	
			char cur = 'a' + j;
			string t = s.substr(0, i) + cur + s.substr(i);
			if (!S.count(t)) S.insert(t);
		}
	}

	cout << S.size() << endl;

	//Output region
	#ifdef MARX
		clog << "TIME: " << clock() - TIME << endl;
	#endif

	return 0;
}