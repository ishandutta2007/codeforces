#include <iostream>
#include <set>

using namespace std;

int n;
int a[100005];
int num[100005], cnt[100005];
set<int> S;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		S.insert(a[i]);
		int x = num[a[i]];
		num[a[i]]++;
		if(x > 0) cnt[x]--;
		cnt[x+1]++;
		
		//for(int j = 0; j <= 5; j++) cout << cnt[j] << " "; cout << endl;
		
		int kind = S.size();
		if((i-1)%kind == 0){
			int y = (i-1)/kind;
			if(cnt[y] == kind-1 && cnt[y+1] == 1) ans = max(ans, i);
		}
		if(kind > 1 && (i-1)%(kind-1) == 0){
			int y = (i-1)/(kind-1);
			if(cnt[y] == kind-1 && cnt[1] == 1) ans = max(ans, i);
			if(cnt[1] == kind) ans = max(ans, i);
		}
	}
	cout << ans << endl;
	
	return 0;
}