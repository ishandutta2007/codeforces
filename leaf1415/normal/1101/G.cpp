#include <iostream>
#define llint long long

using namespace std;

int n;
int a[200005], s[200005], S[200005];

void Gaussian_elimination(int a[])
{
	llint r = 0;
	for(int i = 0; i < 30 && r < n; i++){
		if((a[r]&(1LL<<i)) == 0){
			int p = -1;
			for(int j = r+1; j < n; j++){
				if(a[j] & (1LL<<i)){
					p = j;
					break;
				}
			}
			if(p == -1) goto end;
			swap(a[r], a[p]);
		}
		for(int j = 0; j < n; j++){
			if(j == r) continue;
			if(a[j]&(1LL<<i)) a[j] ^= a[r];
		}
		r++;
		end:;
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) S[i] = S[i-1] ^ a[i];
	
	if(S[n] == 0){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++) s[i] = S[n-i];
	
	Gaussian_elimination(s);
	
	int cnt = 0;
	for(int i = 0; i < n; i++) if(s[i]) cnt++;
	cout << cnt << endl;
	
	return 0;
}