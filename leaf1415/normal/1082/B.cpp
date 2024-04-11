#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int l[100005];
int num = 0;

int main(void)
{
	cin >> n;
	cin >> s;
	
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'G') cnt++, num++;
		else cnt = 0;
		l[i] = cnt;
	}
	cnt = 0;
	for(int i = n-1; i >= 0; i--){
		if(l[i] == 0){
			cnt = 0;
			continue;
		}
		else cnt = max(cnt, l[i]);
		l[i] = max(l[i], cnt);
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(l[i] == 0){
			int tmp = l[i-1] + l[i+1];
			if(num > tmp) tmp++;
			ans = max(ans, tmp);
		}
	}
	if(num == n) ans = num;
	cout << ans << endl;
	
	return 0;
}