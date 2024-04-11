#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N,M;
vector<int> s[2];

long long one(vector<int> s)
{
	int low = s[0], high = s[s.size()-1];
	long long res;

	if (low == high){
		res = s.size();
		res *= s.size() - 1;
		res *= s.size() - 2;
		res /= 6;
	}
	else{
		long long lc=0, hc=0;
		for (int i=0;i<s.size();i++){
			if (s[i] == low) lc++;
			if (s[i] == high) hc++;
		}
		res = 0;
		res += lc * (lc - 1) / 2 * hc;
		res += lc * hc * (hc - 1) / 2;
		res += lc * hc * (s.size() - lc - hc);
	}
	return res;
}

int getmaxone(vector<int> s)
{
	int low = s[0], high = s[s.size()-1];
	return (high - low) * 2;
}

long long two(vector<int> s1, vector<int> s2)
{
	int low2 = s2[0], high2 = s2[s2.size()-1];
	int low1 = s1[0], high1 = s1[s1.size()-1];

	map<int, int> chk1, chk2;
	for (int x : s1) chk1[x]++;
	for (int x : s2) chk2[x]++;

	long long res = 0;
	if (high1 < low2){
		res += (long long)chk2[low2] * (chk2[low2] - 1) / 2 * chk1[high1];
		res += (long long)chk2[low2] * (s2.size() - chk2[low2]) * chk1[high1];
	}
	else if (high2 < low1){
		res += (long long)chk2[high2] * (chk2[high2] - 1) / 2 * chk1[low1];
		res += (long long)chk2[high2] * (s2.size() - chk2[high2]) * chk1[low1];
	}
	else{
		long long all2 = 0, pair = 0;
		for (auto p : chk2){
			long long cnt2 = p.second;
			if (chk1.count(p.first)) res += (cnt2 * (cnt2 - 1) / 2 + cnt2 * all2) * chk1[p.first];
			while (!chk1.empty() && chk1.begin()->first < p.first){
				pair += all2 * chk1.begin()->second;
				chk1.erase(chk1.begin());
			}
			res += cnt2 * pair;
			all2 += cnt2;
			if (chk1.count(p.first)){
				pair += all2 * chk1.begin()->second;
				chk1.erase(chk1.begin());
			}
		}
	}

	return res;
}

int getmaxtwo(vector<int> s1, vector<int> s2)
{
	int low2 = s2[0], high2 = s2[s2.size()-1];
	int low1 = s1[0], high1 = s1[s1.size()-1];
	if (high1 < low2) return (N - low2 + high1) * 2;
	if (high2 < low1) return (N - low1 + high2) * 2;
	return N * 2;
}

int main()
{
	scanf ("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int b,f;
		scanf ("%d %d",&b,&f);
		s[b].push_back(f);
	}

	for (int k=0;k<2;k++){
		sort(s[k].begin(),s[k].end());
	}

	long long res = 0;
	if (s[1].empty()) res = one(s[0]);
	else if (s[0].empty()) res = one(s[1]);
	else{
		int r = max(max(getmaxone(s[0]),getmaxone(s[1])),max(getmaxtwo(s[0],s[1]),getmaxtwo(s[1],s[0])));
		if (getmaxone(s[0]) == r) res += one(s[0]);
		if (getmaxone(s[1]) == r) res += one(s[1]);
		if (getmaxtwo(s[0],s[1]) == r) res += two(s[0],s[1]);
		if (getmaxtwo(s[1],s[0]) == r) res += two(s[1],s[0]);
	}
	printf ("%lld\n",res);

	return 0;
}