#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>
 
using namespace std;
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
 
string E[256], F[256], T[256];
 
int cmp(string &a, string &b) { return szz(a) != szz(b) ? szz(a) < szz(b) : a < b; }
int upd(string &a, string b) {
	if(a == "" || cmp(b, a)) { a = b; return 1; }
	return 0;
}
 
int main() {
	F[0b11110000] = "x";
	F[0b11001100] = "y";
	F[0b10101010] = "z";
	while(1) {
		int ch = 0;
 
		rep(i, 256) if(E[i] != "") ch |= upd(F[i], "(" + E[i] + ")");
		rep(i, 256) if(F[i] != "") ch |= upd(F[i ^ 255], "!" + F[i]);
		rep(i, 256) if(F[i] != "") ch |= upd(T[i], F[i]);
		rep(i, 256) if(T[i] != "") rep(j, 256) if(F[j] != "") ch |= upd(T[i&j], T[i] + "&" + F[j]);
		rep(i, 256) if(T[i] != "") ch |= upd(E[i], T[i]);
		rep(i, 256) if(E[i] != "") rep(j, 256) if(T[j] != "") ch |= upd(E[i|j], E[i] + "|" + T[j]);
 
		if(ch == 0) break;
	}
 
	int n; scanf("%d", &n);
	rep(i, n) {
		char ch[10];
		scanf("%s", ch);
		int c = 0;
		rep(i, 8) c |= (ch[i] - '0') << i;
		printf("%s\n", E[c].c_str());
	}
	return 0;
}