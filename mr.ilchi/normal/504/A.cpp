#include <bits/stdc++.h>
using namespace std;

int n;
int deg[1<<20], s[1<<20];

int main(){
	cin >> n;
	queue <int> Q;
	int res = 0;
	for (int i=0; i<n; i++){
		cin >> deg[i] >> s[i];
		if (deg[i] == 1)
			Q.push(i);
		res+= deg[i];
	}
	cout << res/2 << endl;
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		if (deg[front] != 1)
			continue;
		cout << front << ' ' << s[front] << endl;
		s[s[front]] ^= front;
		deg[s[front]]--;
		if (deg[s[front]] == 1)
			Q.push(s[front]);
	}
	return 0;
}