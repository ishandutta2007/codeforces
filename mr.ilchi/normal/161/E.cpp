/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int t,n; ll ans;
int mat[10][10];
int dp [10][10][10010];

inline bool isPrime(int n){
	
	for (int i=2; i*i<=n; i++) if (n%i==0)
		return false;
	return true;
}

inline void go (int row ,int col){
	
	if (row == n){
		
		int ret = 1;

		for (int i=2; i<=n; i++){
			int tmp = 0;
			for (int j=1; j<=n; j++) if (i!=j)
				tmp = tmp * 10 + mat[i][j];
			ret *= dp[n][i][tmp];
		}

		ans+= ret;

		return;
	}

	if (col == 1){
		bool flag = false;
		for (int j=1; j<row; j++) if (mat[row][j]!=0)
			flag = true;
		if (!flag){
			for (int j=row+1; j<n; j++)
				mat[j][row] = mat[row][j] = 0;
			mat[row][n] = mat[n][row] = 2;
			go (row+1, 1);
		}
		go (row,row+1);
		return;
	}

	if (col == n){
		for (int i=1; i<=9; i+=2){
			mat[row][col] = mat[col][row] = i;
			go (row+1,1);
		}
	}

	else{
		for (int i=0; i<10; i++){
			mat[row][col] = mat[col][row] = i;
			go (row,col+1);
		}
	}
}

int main(){
	
	for (int i=2; i<100000; i++) if (isPrime(i)){
		vector <int> dig;
		int tmp = i;
		while (tmp) { dig.push_back(tmp%10); tmp/=10; }
		for (int i=(int)dig.size(); i<=5; i++){
			for (int j=1; j<=i; j++){
				int now = 0;
				for (int z=i-1; z>=0; z--) if (z!=i-j)
					now = now * 10 + dig[z];
				dp[i][j][now]++;
			}
			dig.push_back(0);
		}
	}

	cin >> t;
	for (int o=1; o<=t; o++){
		int p; cin >> p;
		int cnt=0,tmp=p;
		while (tmp) { cnt++; tmp/=10; }
		n = cnt;
		tmp = p;
		for (int i=n; i>0; i--){
			mat[1][i] = mat[i][1] = tmp%10;
			tmp/=10;
		}
		go(2,1);
		cout << ans << endl;
		ans = 0;
	}

	return 0;
}