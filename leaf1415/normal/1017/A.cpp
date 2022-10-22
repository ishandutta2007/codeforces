#include <bits/stdc++.h>

using namespace std;

int n;
int s[1005];
pair<int, int> p[1005];

int main(void)
{
	cin >> n;
	int a, b, c, d;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c >> d;
		s[i] = a+b+c+d;
	}
	for(int i = 0; i < n; i++){
		p[i] = make_pair(-s[i], i);
	}
	sort(p, p+n);
	
	for(int i = 0; i < n; i++){
		if(p[i].second == 0){
			cout << i+1 << endl;
			break;
		}
	}
	return 0;
}