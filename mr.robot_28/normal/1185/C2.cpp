#include <bits/stdc++.h>
using namespace std;
int main() {
	int n , M , sum = 0;
	cin >> n >> M;
	vector <int> count(101);
	for(int i = 0; i < n;i++) {
		int tmp;
		cin >> tmp;
		int cnt = 0, now = sum + tmp - M;
		//cout << now << ' ' << sum << endl;
		if(now > 0) {
			for(int j = 100;j > 0;j--)
				if(count[j] != 0) {
					
					int tmp_2 = j * count[j];
					//cout << tmp_2 << ' ' << now << endl;
					if(now  <= tmp_2) {
						cnt += (now - 1) / j + 1;
						break;
					}
					now -= tmp_2;
					cnt += count[j];
				} 
		}
	//	cout << cnt << endl << endl;
		count[tmp]++;
		sum += tmp;
		cout << cnt << ' ';
	} 
}