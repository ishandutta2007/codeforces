#include <iostream>
#include <vector>

using namespace std;

int m, k, n, s;
int a[500005], b[500005];
int need[500005], cnt[500005];
int pos[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> k >> n >> s;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= s; i++) cin >> b[i];
	for(int i = 1; i <= s; i++) need[b[i]]++;
	
	int sat = 0;
	for(int i = 1; i <= 500000; i++) if(need[i] == 0) sat++;
	
	int r = 0; 
	for(int l = 1; l <= m; l++){
		while(sat < 500000){
			r++;
			if(r > m){
				pos[l] = -1;
				goto end;
			}
			cnt[a[r]]++;
			if(cnt[a[r]] == need[a[r]]) sat++;
		}
		pos[l] = r;
		if(cnt[a[l]] == need[a[l]]) sat--;
		cnt[a[l]]--;
	}
	end:;
	
	for(int i = 1; i <= m; i++){
		if(pos[i] == -1){
			cout << -1 << endl;
			return 0;
		}
		if(i > m-k+1){
			cout << -1 << endl;
			return 0;
		}
		int tmp = (i-1)%k + max(0, (pos[i]-i+1)-k);
		if(tmp > m-n*k) continue;
		
		cout << tmp << endl;
		vector<int> ans;
		for(int j = 1; j <= (i-1)%k; j++) ans.push_back(i-j), tmp--;
		for(int j = 1; j <= 500000; j++) cnt[j] = 0;
		for(int j = i; j <= pos[i]; j++){
			if(cnt[a[j]] < need[a[j]]) cnt[a[j]]++;
			else{
				if(tmp) ans.push_back(j), tmp--;
			}
		}
		for(int j = 0; j < ans.size(); j++) cout << ans[j] << " "; cout << endl;
		break;
	}
	
	return 0;
}