#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[200005];
int cnt[200005];
vector<int> vec, vec2;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cnt[a[i]]++;
	
	for(int i = 0; i <= 200000; i++){
		if(cnt[i] > 2){
			cout << "NO" << endl;
			return 0;
		}
	}
	for(int i = 0; i <= 200000; i++){
		if(cnt[i]) vec.push_back(i), cnt[i]--;
	}
	for(int i = 0; i <= 200000; i++){
		if(cnt[i]) vec2.push_back(i), cnt[i]--;
	}
	reverse(vec2.begin(), vec2.end());
	
	
	cout << "YES" << endl;
	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	cout << vec2.size() << endl;
	for(int i = 0; i < vec2.size(); i++) cout << vec2[i] << " "; cout << endl;
	
	return 0;
}