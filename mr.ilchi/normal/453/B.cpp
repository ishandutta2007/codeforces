/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std;

const int inf = 1000000000;
const int MAXW = 65;

const int p[] = {2,3,5,7,11,13,17,19,23,29};

bool prime[MAXW];
int n;
int f[MAXW],ans[100];
pair<int,int> a[110];
int dp[110][1<<10][MAXW];
vector <int> Q;

bool is_prime (int x){
	if (x <= 30)
		return false;
	for (int i=2; i*i<=x; i++) if (x%i == 0)
		return false;
	return true;
}

int go (int pos, int mask, int cur){
	if (pos == n)
		return 0;
	if (cur == MAXW)
		return inf;
	if (f[cur] == -1)	
		return go(pos, mask, cur+1);
	int &ret = dp[pos][mask][cur];
	if (ret != -1)
		return ret;
	if (prime[cur])
		return ret = min(inf, go(pos+1, mask, cur+1) + cur - a[pos].first);
	ret = go(pos,mask,cur+1);
	if ((mask & f[cur]) == 0)
		ret = min(ret, go(pos+1,mask | f[cur], cur) + abs(cur - a[pos].first));
	return ret;
}

void print (int pos, int mask, int cur){
	if (pos == n)
		return;
	while (f[cur] == -1)
		cur++;
	if (prime[cur]){
		ans[a[pos].second] = cur;
		print(pos+1, mask, cur+1);
		return;
	}
	if (dp[pos][mask][cur] == go(pos,mask,cur+1))
		print(pos,mask,cur+1);
	else{
		ans[a[pos].second] = cur;
		print(pos+1,mask|f[cur],cur);
	}
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	int cnt = 0;
	for (int i=1; i<MAXW; i++){
		int temp = i;
		for (int j=0; j<10; j++){
			int c = 0;
			while (temp % p[j] == 0){
				temp/= p[j];
				c++;
			}
			if (c > 0)
				f[i] |= (1<<j);
		}
		prime[i] = is_prime(i);
		if (temp != 1 && prime[i] == false)
			f[i] = -1;
	}
	sort(a, a+n);
	memset(dp, -1, sizeof dp);
	go(0,0,1);
	print(0,0,1);
	for (int i=0; i<n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}