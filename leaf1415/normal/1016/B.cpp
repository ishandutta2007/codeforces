#include <iostream>
#include <string>

using namespace std;

int n, m, q;
string s, t;
int occur[1005];
int sum[1005];

int getsum(int l, int r)
{
	if(l > r) return 0;
	if(l == 0) return sum[r];
	return sum[r] - sum[l-1];
}

int main(void)
{
	cin >> n >> m >> q;
	cin >> s >> t;
	
	for(int i = 0; i + t.size() <= s.size(); i++){
		if(s.substr(i, t.size()) == t) occur[i] = 1;
		else occur[i] = 0;
	}
	
	sum[0] = occur[0];
	for(int i = 1; i < s.size(); i++){
		sum[i] = sum[i-1] + occur[i];
	}
	
	int l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		l--, r--;
		cout << getsum(l, r-t.size()+1) << endl;
	}
	return 0;
}