#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#define llint long long

using namespace std;

int n, m, p;
int a[1000005], b[1000005];;

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	scanf("%d %d %d", &n, &m, &p);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < m; i++) scanf("%d", &b[i]);
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % p){
			ans+=i;
			break;
		}
	}
	for(int i = 0; i < m; i++){
		if(b[i] % p){
			ans+=i;
			break;
		}
	}
	cout << ans << endl;
	
	return 0;
}