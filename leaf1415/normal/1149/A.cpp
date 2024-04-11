#include <iostream>

using namespace std;

int n;
int cnt[3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		cnt[a]++;
	}
	
	if(cnt[2] == 0){
		for(int i = 1; i <= n; i++) cout << 1 << " "; cout << endl;
		return 0;
	}
	if(cnt[1] == 0){
		for(int i = 1; i <= n; i++) cout << 2 << " "; cout << endl;
		return 0;
	}
	
	cout << 2 << " " << 1 << " ";
	cnt[1]--, cnt[2]--;
	for(int i = 0; i < cnt[2]; i++) cout << 2 << " ";
	for(int i = 0; i < cnt[1]; i++) cout << 1 << " ";
	cout << endl;
	
	return 0;
}