#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	cin >> n;
	LL a[n];
	LL beg = 0;
	LL num = -1;
	LL cnt = 0;
	LL ans = 0;
	for(LL i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == num){
			cnt++;
		} else {
			//i-cnt to i-1;
			//beg -> beg+cnt-1
			ans += cnt-max(beg+cnt-i+cnt,0LL);
			beg += cnt;
			cnt = 0;
			if(a[i] > 0){
				num = a[i];
				cnt++;
			} else {
				num = -1;
			}
		}
	}
	if(cnt >= 1){
		ans += cnt-max(beg+cnt-n+cnt,0LL);
		beg += cnt;
		cnt = 0;
	}
	cout << ans << endl;
}