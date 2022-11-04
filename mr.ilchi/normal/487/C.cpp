#include <bits/stdc++.h>
using namespace std;

bool mark[2000], vis[2000];
int n;
int perm[2000];

bool isprime(int x){
	if (x==1)
		return false;
	for (int i=2; i*i<=x; i++) if (x%i == 0)
		return false;
	return true;
}

void go (int pos, int cur){
	if (pos == n){
		int cur = 1;
		for (int i=0; i<n; i++){
			cur*=perm[i]; cur%=n;
			cout << cur << ' ';
		}
		cout << endl;
		return;
	}
	for (int i=0; i<n; i++) if (!vis[i]){	
		int newcur = cur * i % n;
		if (!mark[newcur]){
			vis[i] = true;
			perm[pos] = i;
			mark[newcur] = true;
			go(pos+1, newcur);
			mark[newcur] = false;
			vis[i] = false;
		}
	}
}

int POW (int base, int p, int mod){
	int ret = 1, cur = base;
	while (p){
		if (p & 1) ret = (long long)ret * cur % mod;
		cur = (long long)cur * cur % mod;
		p>>=1;
	}
	return ret;
}

int main(){
	cin >> n;
	if (n == 1){
		cout << "YES\n1\n";
		return 0;
	}else if (n==4){
		cout << "YES\n1 3 2 4\n";
		return 0;
	}else if (isprime(n) == false){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	int cur = 1;
	vector<bool> t(n,false);
	vector<bool> t2(n,false);
	for (int i=0; i<n; i++){
		int temp = (i+1LL) * POW(cur, n-2, n) % n;
		cur = (long long)cur * temp % n;
		if (t[temp] || t2[cur])
			assert(false);
		t[temp] = true;
		t2[cur] = true;
		cout << (temp==0 ? n : temp) << endl;
	}
	return 0;
}