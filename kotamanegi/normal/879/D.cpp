#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)                                                                             
#define seg_size 524288
int front[400000] = {};
int back[400000] = {};
int deleted[400000] = {};
vector<long long> ant;
int find_back(int now) {
	if (now < 0||deleted[now] == false) return now;
	back[now] = find_back(back[now]);
	return back[now];
}
int find_front(int now) {
	if (deleted[now] == false) return now;
	front[now] = find_front(front[now]);
	return front[now];
}
int deleting(int now, int k) {
	if (deleted[now] == false) {
		deleted[now] = true;
		k--;
	}
	if (k != 0) {
		back[now] = find_back(now-1);
		deleting(back[now], k);
	}
	return 0;
}
int looking(int now) {
	int back = find_back(now-1);
	if (back == -1||ant[now] != ant[back]) {
		return now;
	}
	else return looking(back);
}
vector<long long> solve(vector<long long> now,int k) {
	ant = now;
	for (int i = 0;i < 400000;++i) {
		back[i] = i - 1;
		front[i] = i + 1;
		deleted[i] = 0;
	}
	int now_cnt = 0,now_itr = 0;
	while (now_itr < now.size()) {
		if (find_back(now_itr - 1) != -1) {
			int back_color = now[find_back(now_itr - 1)];
			if (back_color != now[now_itr]) {
				now_cnt = 1;
				now_itr = find_front(now_itr + 1);
			}
			else {
				now_cnt++;
				if (now_cnt == k) {
					now_cnt = 0;
					deleting(now_itr, k);
					int geko = find_back(now_itr - 1);
					if (geko == -1) {
						now_itr = find_front(now_itr + 1);
					}
					else {
						now_itr = looking(find_back(now_itr - 1));
					}
				}
				else {
					now_itr = find_front(now_itr + 1);
				}
			}
		}else{
			now_itr = find_front(now_itr + 1);
			now_cnt = 1;
		}
	}
	vector<long long> ans;
	for (int i = 0;i < now.size();++i) {
		if (deleted[i] == false) {
			ans.push_back(now[i]);
		}
	}
	return ans;
}
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int n, k, m;
	cin >> n >> k >> m;
	if (n == 1) {
		cout << m%k << endl;
		return 0;
	}
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	vector<int> calc = solve(a,k);
	if (calc.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (m == 1) {
		cout << calc.size() << endl;
		return 0;
	}
	else if (m == 2) {
		vector<long long> hoge_calc;
		for (int i = 0;i < 2;++i) {
			for (int q = 0;q < calc.size();++q) {
				hoge_calc.push_back(calc[q]);
			}
		}
		hoge_calc = solve(hoge_calc, k);
		cout << hoge_calc.size() << endl;
		return 0;
	}
	int	now_cnt = 0;
	int ans_first_itr = 0;
	int ans_second_itr = calc.size() - 1;
	int now_first_itr = 0;
	int now_second_itr = calc.size() - 1;
	while (now_second_itr - now_first_itr > 1) {
		if (calc[now_first_itr] != calc[now_second_itr]) break;
		now_cnt++;
		if (now_cnt == k - 1) {
			now_cnt = 0;
			ans_first_itr = now_first_itr + 1;
			ans_second_itr = now_second_itr - 1;
			now_first_itr++;
			now_second_itr--;
		}
		else {
			if (calc[now_first_itr + 1] == calc[now_second_itr]) {
				now_first_itr++;
			}
			else now_second_itr--;
		}
	}
	if (ans_second_itr - ans_first_itr <  0) {
		if (m % 2 == 1) {
			cout << calc.size() << endl;
		}
		else {
			cout << 0 << endl;
		}
		return 0;
	}
	int digits = 0;
	if (ans_first_itr != ans_second_itr) {
		for (int q = ans_first_itr + 1;q <= ans_second_itr;++q) {
			if (calc[q] != calc[q - 1]) {
				digits = 1;
			}
		}
	}
	if (digits == 0) {
		//same
		vector<int> calc_final;
		for (int i = 0;i <= ans_second_itr;++i) {
			calc_final.push_back(calc[i]);
		}
		int require = (ans_second_itr - ans_first_itr + 1) * (m - 2);
		require %= k;
		if (require != 0) {
			for (int q = 0;q < require;++q) {
				calc_final.push_back(calc[ans_second_itr]);
			}
		}
		for (int i = ans_first_itr;i < calc.size();++i) {
			calc_final.push_back(calc[i]);
		}
		calc_final = solve(calc_final, k);
		cout << calc_final.size() << endl;
		return 0;
	}
	else {
		//not same
		cout << ans_second_itr + 1 + (m - 2) * (ans_second_itr - ans_first_itr+1) + (calc.size() - ans_first_itr)<< endl;
		return 0;
	}
	
return		0;
}
/*
string modulo(string a,int keta) {
	if (a.length() > keta) {
		a.erase(a.begin(), a.end() - keta);
	}
	reverse(a.begin(), a.end());
	while (a.length() != 1) {
		if (a[a.length() - 1] != '0')break;
		a.pop_back();
	}
	reverse(a.begin(), a.end());
	return a;
}
string pluss(string a, string b) {
	if (a.length() < b.length()) swap(a, b);
	reverse(a.begin(), a.end());
	a.push_back('0');
	reverse(a.begin(), a.end());
	int kuriagari = 0;
	for (int i = 0;i < a.length();++i) {
		int geko = (a[a.length() - i - 1]-'0')+ kuriagari;
		if ((int)(b.length()) - i - 1 >= 0) {
			geko += (b[b.length() - i - 1]-'0');
		}
		kuriagari = geko / 10;
		a[a.length() - i - 1] = (geko%10) + '0';
	}
	if (a[0] == '0') {
		a.erase(a.begin() + 0);
	}
	return a;
}
string multiply(string a, string b) {
	string ans = "0";
	string geko = a;
	for (int i = b.length() - 1;i >= 0;--i) {
		if (b[i] != '0') {
			for (int q = 0;q < b[i] - '0';++q) {
				ans = pluss(ans, geko);
			}
		}
		geko.push_back('0');
	}
	return ans;
}
string geko[2000] = {};
int main() {
	string input;
	cin >> input;
	queue<pair<string, int>> wow;
	geko[0] = "1";
	for (int i = 1;i < 2000;++i) {
		string s = geko[i - 1];
		s.push_back('0');
		geko[i] = s;
	}
	wow.push(make_pair("0", 0));
	map<string, int> listings;
	while (wow.empty() == false) {
		pair<string, int> now = wow.front();
		wow.pop();
		for (int i = 0;i < 10;++i) {
			for (int q = 0;q < 10;++q) {
				string tmp;
				tmp.push_back(q + '0');
				tmp.push_back(i + '0');
				string waw = pluss(multiply(geko[now.second], tmp), now.first);
				waw = multiply(waw, waw);
				if (modulo(waw, now.second + 2) == modulo(input,now.second+2)) {
					if (now.second % 100 == 0) {
						cout << now.first << endl;
						cout << endl;
					}
					string gea;
					if (i != 0) {
						gea.push_back(i + '0');
						if (listings[pluss(multiply(geko[now.second], gea), now.first)] == false) {
							listings[pluss(multiply(geko[now.second], gea), now.first)] = true;
							wow.push(pair<string, int>(pluss(multiply(geko[now.second], gea), now.first), now.second + 1));
						}
					}
					else {
						tmp = "0" + now.first;
						if (listings[tmp] == false) {
							listings[tmp] = true;
							wow.push(make_pair(tmp, now.second + 1));
						}
					}
					goto ok;
				}
			}
		ok:;
		}
	}
	return 0;
}
*/