#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int,int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) x.begin(), x.end()

vector <vector<int> > D[2][4005];

int N, A[4010];
const int inf = 1e9;

int Do(int L, int len, int k, int m){
	//m = 0 : left, 1 : right, [L, L+len]
	if(len+1 < k)return 0;
	vector <int> &a = D[m][L][len];
	if(sz(a) >= k && a[k-1] != inf){
		return a[k-1];
	}
	if(m == 0){
		int res = inf;
		if(len+1 >= k){
			int t = Do(L+k, len-k, k, !m) + A[L+k-1] - A[L-1];
			res = t;
		}
		if(len+1 >= k+1){
			int t = Do(L+k+1, len-k-1, k+1, !m) + A[L+k] - A[L-1];
			if(res == inf || res < t)res = t;
		}
		if(res == inf)res = 0;
		while(sz(a) < k)a.pb(inf);
		a[k-1] = res;
		return res;
	}
	else{
		int res = inf;
		if(len+1 >= k)res = min(res, Do(L, len-k, k, !m) - (A[L+len] - A[L+len-k]));
		if(len+1 >= k+1)res = min(res, Do(L, len-k-1, k+1, !m) - (A[L+len] - A[L+len-k-1]));
		if(res == inf)res = 0;
		while(sz(a) < k)a.pb(inf);
		a[k-1] = res;
		return res;
	}
}

void solve(){
	for(int i=1;i<=4000;i++)D[0][i].resize(4001-i), D[1][i].resize(4001-i);
	scanf("%d", &N);
	for(int i=1;i<=N;i++)scanf("%d", A+i),  A[i] += A[i-1];
	printf("%d", Do(1, N-1, 1, 0));
}

int main(){
	int Tc = 1; //scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}