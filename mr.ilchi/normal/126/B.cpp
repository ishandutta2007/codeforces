/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 1000 * 1000 + 5;
const int base = 231;

int p[maxN],pw[maxN];

inline int pref (string s){
	
	int n = (int)s.size();

	p[0] = s[0];

	for (int i=1; i<n; i++)
		p[i] = p[i-1] * base + s[i];

	int ret=0;

	for (int i=1; i<n; i++){
		
		int s=1,e=n;
		
		while (s<=e){
			
			int mid = (s+e)/2;
			int end = i+mid-1;

			if (end>=n) { e=mid-1; continue; }

			if (p[mid-1] == p[end] - pw[mid] * p[i-1]){
				ret = max(ret,mid);
				s = mid+1;
			}
			else
				e = mid-1;
		}
	}

	return ret;
}

int main(){

	ios_base::sync_with_stdio(false);

	string s; cin >> s;

	pw[0] = 1;
	for (int i=1; i<maxN; i++)
		pw[i] = pw[i-1] * base;

	int ans = pref(s.substr(0,s.size()-1));

	p[0] = s[0];
	
	for (int i=1; i<(int)s.size(); i++)
		p[i] = p[i-1] * base + s[i];

	int n = (int)s.size();

	for (int i=ans; i>=1; i--){
			
		if (p[i-1] == p[n-1] - p[n-1-i] * pw[i]){
			cout << s.substr(0,i) << endl;
			return 0;
		}
	}

	cout << "Just a legend" << endl;

	return 0;
}