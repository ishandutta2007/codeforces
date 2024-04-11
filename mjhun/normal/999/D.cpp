#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <stdlib.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int,pair<int,int>> piii;
typedef pair<long long, long long> pll;
#define LB(v,n) lower_bound(v.begin(),v.end(),n)
#define UB(v,n) upper_bound(v.begin(),v.end(),n)
#define FOR(i, init, n) for(int i = init; i < n; i++)
#define RFOR(i, init, end) for(int i = end-1; i >= init; i--)
#define FOR_SET(s) for(set<int>::iterator it=s.begin(); it!=s.end(); it++)
#define OUT(a) cout << a << endl
#define OUT2(a,b) cout << a << " " << b << endl
#define IN(a) cin >> a
#define IN2(a,b) cin >> a >> b
#define IN3(a,b,c) cin >> a >> b >> c
#define FIND(set,num) (set.find(num) != set.end())
#define F first
#define S second

const ll MAXN = 2e5+1;
ll a[MAXN];					// Arreglo con los numeros del input
vector<ll> mod[MAXN];		// Arreglo de vectores de los indices, dependiendo de su modulo
ll n, m, k;

int main() {
	ios::sync_with_stdio(false);
	IN2(n, m);
	ll length = n/m;
	vector<ll> ext;					// Vector de indices
	FOR(i,0,n) {
		IN(a[i]);
		mod[a[i]%m].push_back(i);
	}

	FOR(_,0,2){
		FOR(i, 0, m) {
			while(mod[i].size() > length) {
				ext.push_back(mod[i].back());
				mod[i].pop_back();
			}
			while(ext.size()&&mod[i].size()<length){
				int t = ext.back();
				ext.pop_back();
				a[t]+=(i-a[t]%m+m)%m;
				mod[i].push_back(t);
			}
			k+=ext.size();
		}
	}
	/*
	FOR(i, 0, m) {
		while(mod[i].size() < length) {
			k += (((i - a[ext.back()]) % m) + m) % m ;
			mod[i].push_back(ext.back());
			a[ext.back()] += (((i - a[ext.back()]) % m) + m) % m ;
			ext.pop_back();
		}

	}
*/
	cout << k << endl;
	FOR(i, 0, n) {
		cout << a[i] << " ";
	}


}