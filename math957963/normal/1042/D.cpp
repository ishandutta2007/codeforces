#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD ((1<<31)-1)
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (500010)
#define M (200010)

long long a[N];
int sl[N];
int sr[N];
int l[N];
int r[N];
int nx;

//
void init(void){
	f(i, N){
		a[i] = 0;
		sl[i] = -1;
		sr[i] = -1;
	}
	l[0] = 0;
	r[0] = M;
	nx = 1;
	return;
}

void add(int k){
	stack<int>st;
	int p = 0;
	int y;
	while (l[p] + 1 < r[p]){
		st.push(p);
		y = (l[p] + r[p]) / 2;
		if (k < y){
			if (sl[p] == -1){
				l[nx] = l[p];
				r[nx] = y;
				sl[p] = nx;
				p = nx;
				nx++;
			}
			else{
				p = sl[p];
			}
		}
		else{
			if (sr[p] == -1){
				l[nx] = y;
				r[nx] = r[p];
				sr[p] = nx;
				p = nx;
				nx++;

			}
			else{
				p = sr[p];
			}
		}
	}
	a[p]++;
	while (!st.empty()){
		p = st.top();
		if (sr[p] == -1)a[p] = a[sl[p]];
		else if (sl[p] == -1)a[p] = a[sr[p]];
		else a[p] = a[sl[p]] + a[sr[p]];
		st.pop();
	}
	return;
}

long long sum_search(int ll, int rr, int k){

	long long vl, vr;
	if (rr <= l[k] || r[k] <= ll)return 0;
	else if (ll <= l[k] && r[k] <= rr) return a[k];
	else{
		if (sl[k] != -1)vl = sum_search(ll, rr, sl[k]);
		else vl = 0;
		if (sr[k] != -1)vr = sum_search(ll, rr, sr[k]);
		else vr = 0;
		return (vl + vr);
	}
}


int main(void){
	int n;
	long long k, x, y, ans, s;
	int xx, yy;
	vector<pair<long long,int> >b;
	s = 0;
	ans = 0;
	init();
	scanf("%d %I64d", &n, &k);
	b.push_back(make_pair(s, 0));
	f(i, n){
		scanf("%I64d", &x);
		s += x;
		b.push_back(make_pair(s, i + 1));
	}

	sort(b.begin(), b.end(), greater<pair<long long, int> >());
	xx = 0;

	yy = 0;
	f(i, n + 1){

		if (yy < b.size()){
			while ((b[xx].first - k) < b[yy].first){
				if (yy < b.size()){
					add(b[yy].second);
					yy++;
				}
				if (yy >= b.size()) break;
		}
		}
		ans += sum_search(0, b[xx].second, 0);
		xx++;
	}
	
	printf("%I64d\n", ans);

	return 0;
}