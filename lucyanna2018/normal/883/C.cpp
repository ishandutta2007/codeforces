#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	long long unit, cap, price;
} a[55];
long long tot, tl;

int cmp(const Node &a, const Node &b) {
	return a.unit < b.unit;
}

long long calc(long long rem_tot, long long rem_tl) {
//	cout<<"--- "<<rem_tot<<' '<<rem_tl<<endl;
	if(rem_tot<=0) return 0LL;
	if(rem_tl<=0 || rem_tl / a[1].unit < rem_tot) return -1LL;
	if (a[1].price==0) return 0;
	
	long long slow_tl = 1LL*rem_tot * a[2].unit;
	if(slow_tl <= rem_tl) return 0;
	
	long long delta = slow_tl - rem_tl;
	long long exchange = (a[2].unit - a[1].unit) * a[1].cap;
	long long need1 = (delta-1)/exchange+1;
	return 1LL*a[1].price*need1;
}

int main() {
	cin>>tot>>tl>>a[0].unit;
	a[0].cap = tot; a[0].price = 0;
	cin>>a[1].cap>>a[1].unit>>a[1].price;
	cin>>a[2].cap>>a[2].unit>>a[2].price;
	sort(a, a+3, cmp);
	
	if (tl/a[0].unit < tot) {
		cout<<-1<<endl;
		return 0;
	}
	if (a[0].price==0) {
		cout<<0<<endl;
		return 0;
	}
	
	long long ans = -1LL;
	for(int i=0;1LL*(i-1)*a[0].cap<tot;i++) {
		long long cost = 1LL*i*a[0].price;
		long long rem = calc(tot - 1LL*i*a[0].cap, tl - 1LL*i*a[0].cap*a[0].unit);
		if (rem==-1LL) continue;
//		cout<<cost+rem<<endl;
		if (ans == -1LL || ans > cost+rem) ans = cost+rem;
	}
	cout<<ans<<endl;
	
	return 0;
}