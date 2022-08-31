#include <bits/stdc++.h>
using namespace std;
inline char readChar() {
    static char buffer[4096];
    static char* bptr = buffer + 4096;
    if (bptr == buffer + 4096) {
        fread(buffer, 1, 4096, stdin);
    }
    return *bptr++;
}
int read(){
    register char c = getchar();
    int x = 0;
    for(; c < '0'; c = getchar());
    for(; c >= '0'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
priority_queue<int> q;
int main(){
	priority_queue<int> pq;
	int n, a, b, c, d;
	long long z = 0;
	n = read();
	while (n--) {
	    a = read();
	    b = read();
	    c = read();
	    d = read();
		if(a + b < c + d) {
			z += max(0, a - d) - max(0, b - c);
		} else {
			z += a + c;
			q.push(a + b);
			q.push(c + d);
		}
	}
	while (!q.empty()) {
		q.pop();
		z -= q.top();
		q.pop();
	}
	printf("%I64d",z);
}