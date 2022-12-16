#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
int n;
struct Building{
	ll h,l,r;
}a[maxn];

vector <ll> X;
map <ll, bool> MID;
int xx(int x){return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;}
int ori[maxn << 2];

int mx[maxn << 4],laz[maxn << 4];
void push_up(int rt){
	mx[rt] = max(mx[rt << 1], mx[rt << 1 | 1]);
}

void push_down(int rt){
	if(laz[rt] == 0) return;
	mx[rt << 1] = max(laz[rt], mx[rt << 1]);
	mx[rt << 1 | 1] = max(laz[rt], mx[rt << 1 | 1]);
	
	laz[rt << 1] = max(laz[rt], laz[rt << 1]);
	laz[rt << 1 | 1] = max(laz[rt], laz[rt << 1 | 1]);
	
	laz[rt] = 0;
}

void update(int rt, int  l, int r, int L, int R, int val){
//	printf("D(%d, %d, %d, %d, %d, %d)\n", rt, ox(l), ox(r), ox(L), ox(R), val);
	if(L <= l && r <= R){
		laz[rt] = max(laz[rt], val);
		mx[rt] = max(mx[rt], val);
		return;
	}
	push_down(rt);
	int mid = (l + r) >> 1;
	if(L <= mid) update(rt << 1, l, mid, L, R, val);
	if(R > mid) update(rt << 1 | 1, mid + 1, r, L, R, val);
	push_up(rt);
}

int res[maxn << 2];
void query(int rt, int l, int r){
//	printf("Q(%d, %d, %d)\n", rt, l, r);
	if(l == r){
		res[l] = mx[rt];
		return;
	}
	push_down(rt);
	int mid = (l + r) >> 1;
	query(rt << 1, l, mid);
	query(rt << 1 | 1, mid + 1, r);
}

int main(){
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%lld%lld%lld", &a[i].h, &a[i].l, &a[i].r);
		a[i].l *= 2, a[i].r *= 2;
		X.push_back(a[i].l); X.push_back(a[i].r);
	}
	
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for(int i = 1, tmp = X.size(); i < tmp; ++i) X.push_back((X[i] + X[i - 1]) >> 1), MID[(X[i] + X[i - 1]) >> 1] = 1;
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	
	int len = X.size();
	for(int i = 1; i <= len; ++i){
		if(MID[X[i - 1]]) ori[i] = (X[i - 1] + 1) / 2 - 1;
		else ori[i] = X[i - 1] / 2;
	}
	
	for(int i = 1; i <= n; ++i) update(1, 1, len, xx(a[i].l), xx(a[i].r), a[i].h);
	query(1, 1, len);
	
	int cnt = 2;
	for(int i = 1; i <= len; ++i)
		if(res[i] != res[i - 1]) cnt += 2;
	printf("%d\n", cnt);
	
	for(int i = 1; i <= len; ++i){
		if(res[i] > res[i - 1]) printf("%d %d\n%d %d\n", ori[i], res[i - 1], ori[i], res[i]);
		if(res[i] < res[i - 1]) printf("%d %d\n%d %d\n", ori[i - 1], res[i - 1], ori[i - 1], res[i]);
	}
	printf("%d %d\n%d 0\n", ori[len], res[len], ori[len]);
	return 0;
}
//CF35E