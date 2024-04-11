#include <bits/stdc++.h>
using namespace std;

int N;
int A[101];

int main()
{
	cin >> N;
	int a = 0, b = 0;
	for (int i=1;i<=N;i++){
		int c; cin >> c;
		if (c == 100) a++;
		else b++;
	}
	if ((a+b+b)&1){ puts("NO"); return 0; }
	int m = (a+b+b)>>1;
	for (int i=0;i<=b;i++){
		if (i+i > m) break;
		if (m-i-i <= a){
			puts("YES"); return 0;
		}
	}
	puts("NO");
}