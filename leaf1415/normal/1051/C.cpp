#include <iostream>

using namespace std;

int n;
int s[105];
int cnt[105];
int toA[105];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cnt[s[i]]++;
	
	int sum1 = 0, sum3 = 0, sum3_i;
	for(int i = 1; i <= 100; i++){
		if(cnt[i] == 1){
			if(sum1 % 2 == 0) toA[i]++;
			sum1++;
		}
		if(cnt[i] >= 3){
			sum3++;
			sum3_i = i;
		}
	}
	
	if(sum1 % 2 && sum3 == 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	
	if(sum1 % 2){
		toA[sum3_i] = cnt[sum3_i]-1;
	}
	
	for(int i = 1; i <= n; i++){
		if(toA[s[i]]){
			cout << "A";
			toA[s[i]]--;
		}
		else cout << "B";
	}
	cout << endl;
	
	return 0;
}