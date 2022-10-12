#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

#define i64 long long int
#define vpii vector<pair<int, int> >
// #define i128 __int128_t

string s1, s2;
vector<int> v1, v2;
void trans(string s, vector<int>&v) {
	char cur = '#';int len = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != cur) {
			if (len)v.push_back(len);
			len = 1;
			cur = s[i];
		}
		else
			len++;
	}
	if (len)v.push_back(len);
	reverse(v.begin(), v.end());
}
void output(vpii v) {
	printf("%d\n", (int)v.size());
	for (auto it : v) {
		printf("%d %d\n", it.first, it.second);
	}
}
void proc1(vector<int> v1, vector<int> v2, vpii&op) {
	while (1) {
		int suff1 = 0;if (!v1.empty()) { suff1 = v1.back(); v1.pop_back(); }
		int suff2 = 0;if (!v2.empty()) { suff2 = v2.back(); v2.pop_back(); }
		if (v1.empty() && v2.empty())break;
		op.push_back(make_pair(suff1, suff2));
		int suff11 = 0;if (!v1.empty()) {suff11 = v1.back(); v1.pop_back();	}
		int suff22 = 0;if (!v2.empty()) {suff22 = v2.back(); v2.pop_back(); }
		v1.push_back(suff11 + suff2);
		v2.push_back(suff22 + suff1);
	}
}
void proc(vector<int> v1, vector<int> v2, bool flag, vpii&op) {
	op.clear();
	if (!flag)proc1(v1, v2, op);else {
		vpii bes1, bes2;
		v1.push_back(0);
		proc1(v1, v2, bes1);
		v1.pop_back();
		v2.push_back(0);
		proc1(v1, v2, bes2);
		v2.pop_back();
		op = bes1.size() < bes2.size() ? bes1 : bes2;
	}
}
void cut1(vector<int> v, bool flag, int cnt, string&U, string&V) {
	U = V = "";
	while (!v.empty()) {
		int x = v.back();
		v.pop_back();
		char c = flag ? 'a' : 'b';
		flag = !flag;
		if (cnt > 0) {
			--cnt;
			while (x--)U += c;
		}
		else {
			while (x--)V += c;
		}
	}
}
vpii calc(vector<int> v1, bool flag1, vector<int> v2, bool flag2) {
	vpii cur, bes;
	proc(v1, v2, flag1 == flag2, cur);
	bes = cur;
	int L1 = v1.size(), L2 = v2.size();
	for(int i = max(L1/2-2,0); i <= min(L1/2+2,L1); i++)
		for (int j = max(L2 / 2 - 2, 0); j <= min(L2 / 2 + 2, L2); j++) {
			string U1, V1, U2, V2;
			cut1(v1, flag1, i, U1, V1);
			cut1(v2, flag2, j, U2, V2);
			cur.clear();
			auto tmp = make_pair((int)U1.length(), (int)U2.length());
			vector<int> v3, v4;
			U2 += V1;
			U1 += V2;
			trans(U2, v3);
			trans(U1, v4);
			proc(v3, v4, U2.length()>0&&U1.length()>0&&((U2[0] == 'a') == (U1[0] == 'a')), cur);
			reverse(cur.begin(), cur.end()); cur.push_back(tmp); reverse(cur.begin(), cur.end());
			if (cur.size() < bes.size())
				bes = cur;
		}
	return bes;
}

int main() {
	cin >> s1 >> s2;
	trans(s1, v1);
	trans(s2, v2);
	if (s1[0] == s2[0]) {
		auto bes = calc(v1, s1[0]=='a', v2, s2[0]=='a');

		int a1 = v1.back(), a2 = v2.back();
		v1.pop_back(); v2.pop_back();
		
		v1.push_back(a1 + a2);
		auto bes1 = calc(v1, !(s1[0] == 'a'), v2, s2[0] == 'a');
		reverse(bes1.begin(), bes1.end()); bes1.push_back(make_pair(0, a2)); reverse(bes1.begin(), bes1.end());
		if (bes1.size() < bes.size()) bes = bes1;

		v1.pop_back(); v2.push_back(a1 + a2);
		auto bes2 = calc(v1, s1[0] == 'a', v2, !(s2[0] == 'a'));
		reverse(bes2.begin(), bes2.end()); bes2.push_back(make_pair(a1, 0)); reverse(bes2.begin(), bes2.end());
		if (bes2.size() < bes.size())bes = bes2;

		output(bes);
	}
	else {
		output(calc(v1, s1[0] == 'a', v2, s2[0] == 'a'));
	}
	return 0;
}