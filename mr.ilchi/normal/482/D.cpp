#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000+10;
const int mod = 1000000007;

int n;
int p[MAXN],odd[MAXN],even[MAXN];
vector <int> adj[MAXN];

int sum (const int a, const int b) { int t = a+b; if (t>=mod) t-= mod; return t; }
int mul (const int a, const int b) { return (long long)a * b % mod; }
int sub (const int a, const int b) { int t = a-b+mod; if (t>=mod) t-=mod; return t; }

void dfs (int v){
	int E = 0, O = 0, E2 = 0;
	int OE = 1, OO = 0;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		dfs(temp);
		int newE = sum(sum(sum(E, mul(E, even[temp])), mul(O, odd[temp])), even[temp]);
		int newO = sum(sum(sum(O, mul(O, even[temp])), mul(E, odd[temp])), odd[temp]);
		E2 = sum(E2, sum(even[temp], mul(E2, even[temp])));
		E = newE, O = newO;
		int newOE = sum(OE, mul(OO, odd[temp]));
		int newOO = sum(OO, mul(OE, odd[temp]));
		OO = newOO, OE = newOE;
	}
	odd [v]= sub(sum(1, mul(2, E)), E2);
	even[v]= sub(mul(2,O), OO);
}

int main(){
	cin >> n;
	for (int i=1; i<n; i++){
		cin >> p[i];
		p[i]--;
		adj[p[i]].push_back(i);
	}
	dfs(0);
	cout << sum(odd[0], even[0]) << endl;
	return 0;
}