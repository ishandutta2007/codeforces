#include<iostream>
#include<string>
#include<stack>

using namespace std;

const int INF = 1e7;

int a, d[100002], f, f1, i, k, l1, ff, tp, ans1, ans, s;

signed main() {
	string sequence;
	cin >> sequence;
	int n = sequence.size(), l = INF;
	stack <pair <char, int>> q; 
	for (i = 0; i < n; i++) {
		if (sequence[i] == '(' || sequence[i] == '[') 
			q.push(make_pair(sequence[i], i));
		else {
			if (q.empty()) 
				continue;
			if (sequence[i] == q.top().first + 2) { 
				d[i] = d[i - 1] + d[q.top().second - 1] + 1; 
				q.pop(); 
			}
			else
				if (sequence[i] == q.top().first + 1) {
					d[i] = d[i - 1] + d[q.top().second - 1]; \
					q.pop();
				}
				else
					while (!q.empty()) 
						q.pop();
			if (d[i] > k) { 
				k = d[i]; 
				l = i;
			}
		}
	}
	while (!q.empty()) 
		q.pop();
	cout << k << '\n';
	string str_ans;
	for (i = l; k > 0 || !q.empty(); i--) {
		str_ans = sequence[i] + str_ans;
		if (sequence[i] == '[') 
			k--;
		if (sequence[i] == ')' || sequence[i] == ']') 
			q.push(make_pair(sequence[i], i));
		else {
			if (sequence[i] == q.top().first - 2) 
				q.pop();
			else
				if (sequence[i] == q.top().first - 1) 
					q.pop();
		}

	}
	cout << str_ans;
	//system("pause");
}