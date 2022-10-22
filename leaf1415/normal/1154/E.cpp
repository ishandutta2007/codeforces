#include <iostream>

using namespace std;

int n, k;
int a[200005];
int l[200005], r[200005];
int ans[200005], pos[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) pos[a[i]] = i;
	for(int i = 1; i <= n; i++) l[i] = i-1, r[i] = i+1;
	
	int t = 1;
	for(int i = n; i >= 1; i--){
		int p = pos[i], cnt;
		if(ans[p]) continue;
		ans[p] = t;
		
		cnt = k;
		while(cnt){
			p = l[p];
			if(p == 0) break;
			ans[p] = t, cnt--;
			l[r[p]] = l[p];
			r[l[p]] = r[p];
		}
		p = pos[i], cnt = k;
		while(cnt){
			p = r[p];
			if(p == n+1) break;
			ans[p] = t, cnt--;
			r[l[p]] = r[p];
			l[r[p]] = l[p];
		}
		p = pos[i];
		r[l[p]] = r[p];
		l[r[p]] = l[p];
		
		if(t == 1) t = 2;
		else t = 1;
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i];
	cout << endl;
	
	return 0;
}