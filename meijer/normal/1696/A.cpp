#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = (0);
	(cin)>>(t);
	while ((t)>(0)) {
		int n = (0);
		int z = (0);
		((cin)>>(n))>>(z);
		int i = (0);
		int ans = (0);
		while ((i)<(n)) {
			int a = (0);
			(cin)>>(a);
			if (((a)|(z))>(ans)) {
				(ans)=((a)|(z));
			};
			(i)+=(1);
		};
		cout << (ans) << endl;
		(t)-=(1);
	};
}