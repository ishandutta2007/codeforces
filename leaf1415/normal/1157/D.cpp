#include <iostream>
#define llint long long

using namespace std;

llint n, k;
llint ans[100005];

int main(void)
{
  cin >> n >> k;
  if(n < k*(k+1)/2){
    cout << "NO" << endl;
    return 0;
  }
  /*if(k <= 35 && (1LL<<k)-1 < n){
    cout << "NO" << endl;
    return 0;
  }*/
	
	ans[0] = 1000000000;
  for(int i = 1; i <= k; i++) ans[i] = i;
  llint rem = n - k*(k+1)/2, sum = 0;
  for(int i = 1; i <= k; i++){
    ans[i] += sum;
    llint x = min(rem / (k-i+1), ans[i-1]*2-ans[i]);
    ans[i] += x, sum += x;
    rem -= x * (k-i+1);
  }
	
	llint s = 0;
	for(int i = 1; i <= k; i++) s += ans[i];
	if(s != n){
		cout << "NO" << endl;
		return 0;
	}

  cout << "YES" << endl;
  for(int i = 1; i <= k; i++) cout << ans[i] << " "; cout << endl;
  return 0;
}