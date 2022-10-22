#include <iostream>

using namespace std;

int n, N;
int a[205];
int used[105];

int bit[205];
int sum(int i)
{
	int ret = 0;
	while(i > 0){
		ret += bit[i];
		i -= i&(-i);
	}
	return ret;
}
void add(int i, int x)
{
	while(i <= N){
		bit[i] += x;
		i += i&(-i);
	}
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= 2*n; i++) cin >> a[i];
	N = n*2;
	
	int id = 1;
	for(int i = 1; i <= N; i++){
		if(used[a[i]]) a[i] = 2*used[a[i]];
		else{
			used[a[i]] = id++;
			a[i] = 2*used[a[i]]-1;
		}
	}
	
	//for(int i = 1; i <= N; i++) cout << a[i] << " "; cout << endl;
	
	int ans = 0;
	for(int i = 1; i <= N; i++){
		ans += (i-1) - sum(a[i]);
		add(a[i], 1);
	}
	cout << ans << endl;
	return 0;
}