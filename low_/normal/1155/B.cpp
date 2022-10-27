#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; string S;
	int vcnt, pcnt;

	cin>>n>>S;
	vcnt=(n-11)/2;
	pcnt=(n-11)/2-1;

	vector <bool> stay;
	stay.assign(n, 1);
	for (int i=0; i<S.size(); i++){
		if (S[i]=='8' && pcnt>0){
			pcnt--;
			stay[i]=0;
		}
		else if (S[i]!='8' && vcnt>0){
			vcnt--;
			stay[i]=0;
		}
	}
	string Fin="";
	for (int i=0; i<n; i++) if (stay[i]==1) Fin.push_back(S[i]);
	if (Fin[0]=='8' && Fin[1]=='8')cout<<"YES";
	else cout<<"NO";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/