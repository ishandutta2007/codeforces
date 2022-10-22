#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[300005], b[300005];
llint wa[300005], wb[300005];
llint wa2[300005], wb2[300005];
llint sum[300005], wsum[3000005], wsum2[3000005];

llint A[300005], B[300005];

llint getsum(llint sum[], llint l)
{
	return sum[n] - sum[l-1];
}

llint calc(int p)
{
	if(p > n) return 0;
	llint ret, x = p-1;
	if(p % 2) ret = getsum(wsum, p) + x*getsum(sum, p);
	else ret = getsum(wsum2, p) + x*getsum(sum, p);
	
	llint tmp = 0;
	if(p % 2) tmp += (x*2)*a[p] + (x*2+1)*b[p];
	else tmp += (x*2)*b[p] + (x*2+1)*a[p];
	
	tmp += calc(p+1);
	ret = max(ret, tmp);
	return ret;
}

llint make()
{
	for(int i = 1; i <= n; i++) wa[i] = a[i] * (i-1);
	for(int i = 1; i <= n; i++) wb[i] = b[i] * (2*n-i);
	
	for(int i = 1; i <= n; i++) wb2[i] = b[i] * (i-1);
	for(int i = 1; i <= n; i++) wa2[i] = a[i] * (2*n-i);
	
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i] + b[i];
		wsum[i] = wsum[i-1] + wa[i] + wb[i];
		wsum2[i] = wsum2[i-1] + wa2[i] + wb2[i];
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	
	make();
	
	llint ans = calc(1);
	cout << ans << endl;
	
	return 0;
}