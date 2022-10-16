#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int l[4] = {2, 3, 5, 7};

bool isPrime(int n){
	for (int i = 2; i * i <= n; ++i){
		if (n % i == 0) return false;
	}
	return true;
}

bool say(int n){
	cout << n << endl;
	cout.flush();
	string s; cin >> s;
	return s == "yes";
}

void check(int n){
	for (int i = n; i * n <= 100; ++i){
		if (isPrime(i)){
			bool d = say(i * n);
			if (d){
				cout << "composite" << endl;
				exit(0);
			}
		}
	}
	cout << "prime" << endl;
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	for (int i = 0; i < 4; ++i){
		if (say(l[i])){
			check(l[i]);
			return 0;
		}
	}

	cout << "prime" << endl;
	cout.flush();

	return 0;
}