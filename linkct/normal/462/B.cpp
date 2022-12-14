#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

char str[100005];
int cnt[30], n, k, ans[30];
ll answer;

int main(){
	int i, delta;
	scanf("%d%d%s", &n, &k, str + 1);
	for(i = 1; i <= n; ++ i)
		cnt[str[i] - 'A' + 1] ++;
	sort(cnt + 1, cnt + 27);
	for(i = 26; i >= 1; -- i){
		delta = min(k, cnt[i]);
		ans[++ ans[0]] = delta;
		k -= delta;
		if(!k) break;
	}
	for(i = 1; i <= ans[0]; ++ i)
		answer += (ll)ans[i] * ans[i];
	cout << answer << endl;
	return 0;
}