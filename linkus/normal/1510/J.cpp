#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int C = 5;

int n;
char S[N];

bool krata(int i, int x) {
	for (int j = i; j >= max(i - x, x); j--) {
		if (S[j] == '#') {
			return true;
		}
	}
	return false;
}

bool check(int x) {
	int ile = 0;
	for (int i = n - 1; i >= x; i--) {
		if (S[i] == '_') {
			ile++;
		}
		else {
			if (i + ile == n - 1 && ile == x) {
				ile = 0;
				continue;
			}
			if ((ile > 0 || i == n - 1) && ile < x + 1) {
				return false;
			}
			ile = 0;
		}
	}
	return true;
}

bool solve0() {
	vector<int> res;
	bool juz = true;
	for (int i = 0; i < n; i++) {
		if (S[i] == '#') {
			juz = false;
			break;
		}
	}
	if (juz) {
		printf("0\n");
		return true;
	}
	if (S[0] == '_' || S[n - 1] == '_') {
		return false;
	}
	

	for (int i = 1; i < n - 1; i++) {
		if (S[i] == '_' && S[i + 1] == '_') {
			return false;
		}
	}
	int ile = 0;
	for (int i = 0; i < n; i++) {
		if (S[i] == '#') {
			ile++;
		}
		else {
			res.push_back(ile);
			ile = 0;
		}
	}
	res.push_back(ile);
	printf("%d\n", (int)res.size());
	for (auto v : res) {
		printf("%d ", v);
	}
	printf("\n");
	return true;
}

bool solve1() {
	vector<int> res;
	if (S[0] == '#') {
		return false;
	}
	if (n < 2) {
		return false;
	}
	if (!check(1)) {
		return false;
	}
	
	int ind = 1;
	while (S[ind] == '_') {
		ind++;
	}
	if ((ind - 1) % 2 == 1) {
		return false;
	}

	int ile = 0;
	for (int i = ind; i < n; i++) {
		if (krata(i, 1)) {
			if (ile % 2 == 0 && ile > 0) {
				return false;
			}
			ile = 0;
		}
		else {
			ile++;
		}
	}
	
	if (ile % 2 == 1) {
		return false;
	}
	
	ile = 0;
	int ile2 = 0;
	for (int i = 1; i < n; i++) {
		if (krata(i, 1)) {
			ile++;
			ile2 = 0;
		}
		else {
			if (ile > 0) {
				res.push_back(ile);
			}
			ile = 0;
			
			ile2++;
			if (ile2 % 2 == 0) {
				res.push_back(1);
				ile2 = 0;
			}
		}
	}
	if (ile > 0) {
		res.push_back(ile);
	}
	
	printf("%d\n", (int)res.size());
	for (int v : res) {
		printf("%d ", v);
	}
	return true;
}
			
		
		

bool solve(int x) {
	if (n <= x) {
		return false;
	}
	if (!check(x)) {
		return false;
	}
	
	for (int i = 0; i < x; i++) {
		if (S[i] == '#') {
			return false;
		}
	}
	int ind = x;
	while (S[ind] == '_') {
		ind++;
	}
	
	if (ind - x == 1) {
		return false;
	}
	
	
	int ile = 0;
	for (int i = ind; i < n; i++) {
		if (krata(i, x)) {
			if (ile == 2) {
				return false;
			}
			ile = 0;
		}
		else {
			ile++;
		}
	}
	if (ile == 1) {
		return false;
	}
	
	
	vector<int> res;
	for (int i = 1; i < ind - x; i += 2) {
		if (i + 2 == ind - x) {
			res.push_back(2);
		}
		else {
			res.push_back(1);
		}
	}
	
	ile = 0;
	int ile2 = 0;
	for (int i = ind; i < n; i++) {
		if (krata(i, x)) {
			for (int j = 2; j < ile2; j += 2) {
				if (j + 2 == ile2) {
					res.push_back(2);
				}
				else {
					res.push_back(1);
				}
			}
			ile2 = 0;
			ile++;
		}
		else {
			if (ile > 0) {
				res.push_back(ile);
			}
			ile = 0;
			ile2++;
		}
	}
	
	for (int i = 1; i < ile2; i += 2) {
		if (i + 2 == ile2) {
			res.push_back(2);
		}
		else {
			res.push_back(1);
		}
	}
	if (ile > 0) {
		res.push_back(ile);
	}
	
	printf("%d\n", (int)res.size());
	for (int v : res) {
		printf("%d ", v);
	}
	return true;
}
				
			
	

int main()
{
	scanf("%s", &S);
	n = strlen(S);
	
	if (solve0()) {
		return 0;
	}
	if (solve1()) {
		return 0;
	}
	for (int i = 2; i <= C; i++) {
		if (solve(i)) {
			return 0;
		}
	}
	printf("-1\n");
	
}