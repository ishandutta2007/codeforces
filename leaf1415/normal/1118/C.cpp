#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt[1005];
vector<int> vec4, vec2, vec1;
int ans[25][25];

int main(void)
{
	cin >> n;
	int a;
	for(int i = 1; i <= n*n; i++){
		cin >> a;
		cnt[a]++;
	}
	
	for(int i = 1; i <= 1000; i++){
		for(int j = 0; j < cnt[i]/4; j++) vec4.push_back(i);
		cnt[i] %= 4;
		for(int j = 0; j < cnt[i]/2; j++) vec2.push_back(i);
		cnt[i] %= 2;
		for(int j = 0; j < cnt[i]; j++) vec1.push_back(i);
	}
	
	int m = (n+1)/2;
	for(int i = 1; i <= n/2; i++){
		for(int j = 1; j <= n/2; j++){
			if(vec4.size() == 0){
				cout << "NO" << endl;
				return 0;
			}
			int x = vec4.back();
			vec4.pop_back();
			ans[i][j] = ans[n+1-i][j] = ans[i][n+1-j] = ans[n+1-i][n+1-j] = x;
		}
	}
	for(int i = 0; i < vec4.size(); i++) vec2.push_back(vec4[i]), vec2.push_back(vec4[i]);
	
	if(n%2){
		for(int i = 1; i <= n/2; i++){
			if(vec2.size() == 0){
				cout << "NO" << endl;
				return 0;
			}
			int x = vec2.back();
			vec2.pop_back();
			ans[i][n/2+1] = ans[n+1-i][n/2+1] = x;
		}
		for(int i = 1; i <= n/2; i++){
			if(vec2.size() == 0){
				cout << "NO" << endl;
				return 0;
			}
			int x = vec2.back();
			vec2.pop_back();
			ans[n/2+1][i] = ans[n/2+1][n+1-i] = x;
		}
		for(int i = 0; i < vec2.size(); i++) vec1.push_back(vec2[i]), vec1.push_back(vec2[i]);
	
		if(vec1.size() == 0){
			cout << "NO" << endl;
			return 0;
		}
		int x = vec1.back();
		vec1.pop_back();
		ans[n/2+1][n/2+1] = x;
		
		if(vec1.size() != 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}