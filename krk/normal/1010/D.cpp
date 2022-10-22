#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;
const int Maxl = 10;

char tmp[Maxl];
int n;
string op[Maxn];
int A[Maxn], B[Maxn];
int res[Maxn];
int ans[Maxn];

void Read(string &s)
{
	scanf("%s", tmp); s = tmp;
}

void Eval(int v)
{
	if (op[v] == "IN") res[v] = A[v];
	else {
		Eval(A[v]);
		if (op[v] != "NOT") Eval(B[v]);
		if (op[v] == "AND") res[v] = (res[A[v]] & res[B[v]]);
		else if (op[v] == "OR") res[v] = (res[A[v]] | res[B[v]]);
		else if (op[v] == "XOR") res[v] = (res[A[v]] ^ res[B[v]]);
		else if (op[v] == "NOT") res[v] = !res[A[v]];
	}
}

int Get(int val, int mod)
{
	return mod == 1? val: !val;
}

void Traverse(int v, ii p)
{
	if (p.first == 0)
		if (op[v] == "IN") ans[v] = p.second;
		else {
			Traverse(A[v], p);
			if (op[v] != "NOT") Traverse(B[v], p);
		}
	else if (op[v] == "IN") ans[v] = Get(!A[v], p.second);
		 else if (op[v] == "NOT") Traverse(A[v], ii(p.first, -p.second));
		 else if (op[v] == "AND") {
		 	if (res[A[v]] == 0) Traverse(B[v], ii(0, Get(0, p.second)));
		 	else Traverse(B[v], p);
		 	if (res[B[v]] == 0) Traverse(A[v], ii(0, Get(0, p.second)));
		 	else Traverse(A[v], p);
		 } else if (op[v] == "OR") {
		 	if (res[A[v]] == 1) Traverse(B[v], ii(0, Get(1, p.second)));
		 	else Traverse(B[v], p);
		 	if (res[B[v]] == 1) Traverse(A[v], ii(0, Get(1, p.second)));
		 	else Traverse(A[v], p);
		 } else if (op[v] == "XOR") {
		 	if (res[A[v]] == 0) Traverse(B[v], p);
		 	else Traverse(B[v], ii(p.first, -p.second));
		 	if (res[B[v]] == 0) Traverse(A[v], p);
		 	else Traverse(A[v], ii(p.first, -p.second));
		 }
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		Read(op[i]); scanf("%d", &A[i]);
		if (op[i] != "IN" && op[i] != "NOT") scanf("%d", &B[i]);
	}
	Eval(1);
	Traverse(1, ii(1, 1));
	for (int i = 1; i <= n; i++)
		if (op[i] == "IN")
			printf("%d", ans[i]);
	printf("\n");
	return 0;
}