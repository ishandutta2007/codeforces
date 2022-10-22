#include <iostream>

using namespace std;

int n, q;
int l[5005], r[5005];
int a[5005], d[5005];
int cnt1[5005], cnt2[5005];

int main(void)
{
	cin >> n >> q;
	for(int i = 1; i <= q; i++) cin >> l[i] >> r[i];
	
	for(int i = 1; i <= q; i++){
		d[l[i]]++, d[r[i]+1]--;
	}
	for(int i = 1; i <= n; i++){
		a[i] = a[i-1] + d[i];
	}
	for(int i = 1; i <= n; i++){
		cnt1[i] = cnt1[i-1];
		cnt2[i] = cnt2[i-1];
		if(a[i] == 1) cnt1[i]++;
		if(a[i] == 2) cnt2[i]++;
	}
	int cnt0 = 0;
	for(int i = 1; i <= n; i++) if(a[i] == 0) cnt0++;
	
	int ans = n;
	for(int i = 1; i <= q; i++){
		for(int j = 1; j <= q; j++){
			if(i >= j) continue;
			if(r[i] < l[j] || r[j] < l[i]){
				ans = min(ans, cnt1[r[i]]-cnt1[l[i]-1] + cnt1[r[j]]-cnt1[l[j]-1]);
				//cout << i << " " << j << " " << ans << endl;
				continue;
			}
			
			int s = i, t = j;
			int L = min(l[s], l[t]), R = max(r[s], r[t]);
			int inL = max(l[s], l[t]), inR = min(r[s], r[t]);
			int tmp = cnt1[inL-1]-cnt1[L-1] + cnt1[R]-cnt1[inR] + cnt2[inR]-cnt2[inL-1];
			ans = min(ans, tmp);
			
			/*cout << L << " " << R << " " << inL << " " << inR << endl;
			cout << i << " " << j << endl;
			cout << tmp << endl;*/
		}
	}
	cout << n - ans - cnt0 << endl;
	
	return 0;
}