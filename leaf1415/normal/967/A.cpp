#include <iostream>

using namespace std;

int n, s;
int t[105];

int main(void)
{
	cin >> n >> s;
	int h, m;
	for(int i = 0; i < n; i++){
		cin >> h >> m;
		t[i] = h * 60 + m;
	}
	
	int ans;
	if(t[0] >= s+1){
		ans = 0;
		goto end;
	}
	for(int i = 0; i < n-1; i++){
		if(t[i+1] - t[i] >= 2*s + 2){
			ans = t[i] + s+1;
			goto end;
		}
	}
	ans = t[n-1] + s+1;
	
	end:;
	cout << ans / 60 << " " << ans % 60 << endl;
	return 0;
}