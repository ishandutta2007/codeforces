/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const int MAXN = 100000+10;

bool mark[MAXN];
int n;
int nex[MAXN],pre[MAXN];
vector < vector <int> > ans1[6],ans2[6];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=1; i<=n; i++){
		int x; cin >> x;
		nex[x] = i;
		pre[i] = x;
	}
	int rep = 0;
	for (int i=1; i<=n; i++) if (!mark[i]){
		rep++;
		int tmp=i,sz=0;
		while (!mark[tmp]){ 
			mark[tmp] = true; 
			tmp=nex[tmp]; 
			sz++;
		}
		if (sz==1)
			continue;
		while (true){
			if (sz<6){
				vector <int> A,B;
				int cur = i;
				for (int j=0; j<sz; j++){
					A.push_back(cur);
					B.push_back(pre[cur]);
					cur = nex[cur];
				}
				ans1[sz].push_back(A);
				ans2[sz].push_back(B);
				break;
			}
			else{
				vector <int> A,B;
				int cur = nex[i];
				for (int j=1; j<5; j++){
					A.push_back(nex[cur]);
					B.push_back(cur);
					cur = nex[cur];
				}
				A.push_back(nex[i]);
				B.push_back(cur);
				nex[i] = cur;
				pre[cur] = i;
				ans1[5].push_back(A);
				ans2[5].push_back(B);
				sz-=4;
			}
		}
	}
	while (!ans1[2].empty() && !ans1[3].empty()){
		int sz2 = (int)ans1[2].size();
		int sz3 = (int)ans1[3].size();
		vector <int> AA = ans1[2][sz2-1]; AA.insert(AA.end(),ans1[3][sz3-1].begin(),ans1[3][sz3-1].end());
		vector <int> BB = ans2[2][sz2-1]; BB.insert(BB.end(),ans2[3][sz3-1].begin(),ans2[3][sz3-1].end());
		ans1[2].pop_back(); ans1[3].pop_back();
		ans2[2].pop_back(); ans2[3].pop_back();
		ans1[5].push_back(AA);
		ans2[5].push_back(BB);
	}
	while (ans1[2].size()>1){
		int sz = (int)ans1[2].size();
		vector <int> AA = ans1[2][sz-2]; AA.insert(AA.end(),ans1[2][sz-1].begin(),ans1[2][sz-1].end());
		vector <int> BB = ans2[2][sz-2]; BB.insert(BB.end(),ans2[2][sz-1].begin(),ans2[2][sz-1].end());
		ans1[2].pop_back(); ans1[2].pop_back();
		ans2[2].pop_back(); ans2[2].pop_back();
		ans1[4].push_back(AA);
		ans2[4].push_back(BB);
	}
	vector < vector <int> > last1,last2;
	while (ans1[3].size()>2){
		int sz = (int)ans1[3].size();
		int a = ans1[3][sz-1][0];
		int b = ans1[3][sz-1][1];
		int c = ans1[3][sz-1][2];
		
		ans1[3][sz-3].push_back(a);
		ans2[3][sz-3].push_back(c);
		ans1[3][sz-3].push_back(c);
		ans2[3][sz-3].push_back(a);
		
		ans1[3][sz-2].push_back(b);
		ans2[3][sz-2].push_back(a);
		ans1[3][sz-2].push_back(a);
		ans2[3][sz-2].push_back(b);
		
		last1.push_back(ans1[3][sz-3]);
		last2.push_back(ans2[3][sz-3]);
		last1.push_back(ans1[3][sz-2]);
		last2.push_back(ans2[3][sz-2]);
		ans1[3].resize(sz-3);
		ans2[3].resize(sz-3);
	}
	cout << ans1[2].size() + ans1[3].size() + ans1[4].size() + ans1[5].size() + last1.size() << endl;
	for (int rep=5; rep>1; rep--)
		for (int i=0; i<(int)ans1[rep].size(); i++){
			cout << rep << endl;
			for (int j=0; j<(int)rep; j++) cout << ans1[rep][i][j] << ' '; cout << endl;
			for (int j=0; j<(int)rep; j++) cout << ans2[rep][i][j] << ' '; cout << endl;
		}
	for (int i=0; i<(int)last1.size(); i++){
		cout << 5 << endl;
		for (int j=0; j<5; j++) cout << last1[i][j] << ' '; cout << endl;
		for (int j=0; j<5; j++) cout << last2[i][j] << ' '; cout << endl;
	}
	return 0;
}