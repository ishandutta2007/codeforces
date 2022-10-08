
#include <iostream>

using namespace std;

int n, a[100];
int score[3][3] = {{-1, 3, 4}, {3, -1, -1}, {4, -1, -1}};
int points = 0;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for(int i = 1; i < n; i++) {
		points += score[a[i]][a[i - 1]];
		if(score[a[i - 1]][a[i]] == -1) {
			cout << "Infinite";
			return 0;
		}
		if(i > 1 && a[i - 2] == 2 && a[i] == 1) {
			points--;
		}
	}
	cout << "Finite" << endl << points;
}