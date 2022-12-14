#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX 1000005
using namespace std;
typedef long long int ll;

struct input{
	int n, p, n_;
	bool operator < (const input& rhs) const{
		return n < rhs.n;
	}
}seq[MAX];
int n, stat[MAX], stat2[MAX], bit[MAX], op[MAX];

bool cmp(const input& lhs, const input& rhs){
	return lhs.p < rhs.p;
}
int query(int pos){
	int retval = 0;
	pos ++;
	while(pos){
		retval += bit[pos];
		pos -= pos & (-pos);
	}
	return retval;
}
void update(int pos, int val){
	pos ++;
	while(pos <= n){
		bit[pos] += val;
		pos += pos & (-pos);
	}
}
int main(){
	int i;
	ll ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i].n);
		seq[i].p = i;
	}
	sort(seq + 1, seq + 1 + n);
	seq[1].n_ = 1;
	for(i = 2; i <= n; ++ i)
		seq[i].n_ = seq[i - 1].n_ + ((seq[i].n == seq[i - 1].n) ? 0 : 1);
	sort(seq + 1, seq + 1 + n, cmp);
	for(i = n; i > 1; -- i){
		stat[seq[i].n_] ++;
		op[i] = stat[seq[i].n_];
		update(op[i], 1);
	}
	for(i = 1; i < n; ++ i){
		stat2[seq[i].n_] ++;
		ans += query(stat2[seq[i].n_] - 1);
		update(op[i + 1], -1);
	}
	cout << ans << endl;
	return 0;
}