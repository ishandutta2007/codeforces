#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
	cin >> N;
	if (N <= 2){ puts("1\n1"); return 0; }
	if (N == 3){ puts("2\n1 3"); return 0; }
	deque <int> dq;
	dq.push_front(1);
	for (int i=N,j=0;i>1;i--,j^=1){
		if (j) dq.push_back(i);
		else dq.push_front(i);
	}
	printf("%d\n", N);
	for (int n: dq) printf("%d ", n); puts("");
}