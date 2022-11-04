#include <bits/stdc++.h>
using namespace std;

int n;
string s[100];
long long MASK,f[100];
double ans;
double pr[100];

inline void go (int pos, long long mask, int rem){
	if (mask == MASK)
		return;
	if (pos == (int)s[0].size()){
		ans+= pr[(int)s[0].size()-rem];
		return;
	}
	go(pos+1, mask, rem+1);
	go(pos+1, mask | f[pos], rem);
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<=(int)s[0].size(); i++){
		pr[i] = 1.0;
		for (int j=1; j<=i; j++)
			pr[i]*= (i-j+1.0)/((int)s[0].size()-j+1.0);
	}
	for (int i=0; i<n; i++){
		for (int k=0; k<(int)s[i].size(); k++)
			f[k] = 0LL;
		for (int j=0; j<n; j++) if (i != j)
			for (int k=0; k<(int)s[i].size(); k++) if (s[i][k] != s[j][k])
				f[k]|= (1LL<<j);
		MASK = (1LL<<n)-1-(1LL<<i);
		go(0, 0LL, 0);
	}
	cout << fixed << setprecision(10) << ans/n << endl;
	return 0;
}