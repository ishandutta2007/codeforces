#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint N;
llint V[100005], T[100005];
llint sumT[100005];
llint ans[100005];
llint melt[100005];

int main(void)
{
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> V[i];
	for(int i = 1; i <= N; i++) cin >> T[i];
	for(int i = 1; i <= N; i++) sumT[i] = sumT[i-1] + T[i];
	
	for(int i = 1; i <= N; i++){
		int day = lower_bound(sumT+i, sumT+N+1, V[i] + sumT[i-1]) - sumT;
		ans[day] -= sumT[day] - sumT[i-1] - V[i];
		melt[day]++;
	}
	
	llint cnt = 0;
	for(int i = 1; i <= N; i++){
		cnt++;
		ans[i] += cnt * T[i];
		cnt -= melt[i];
	}
	
	for(int i = 1; i <= N; i++){
		cout << ans[i];
		if(i < N) cout << " ";
	}
	cout << endl;
	return 0;
}