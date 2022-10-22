#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long int64;
const int64 offset[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool occ (int64 i, int64 j, vector<vector<char> > const &field) {
	if ((i < 0) || (i >= field.size()) || (j < 0) || (j >= field[0].size()))
		return true;
	return (field[i][j] != '.') && (field[i][j] != ',');
}

bool isknown (int64 i, int64 j, vector<vector<char> > const &field) {
	int cnt = 0;
	for (int k = 0; k < 4; k++)
		if (occ(i + offset[k][0], j + offset[k][1], field))
			cnt++;
	return (cnt == 3) && ((field[i][j] == '.') || (field[i][j] == ','));
}

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	int64 n, m, i, j, k, empties = 0;
	cin >> n >> m;
	vector<pair<int, int> > known;
	//vector<pair<int, int> > empty;
	vector<vector<char> > field(n, vector<char>(m));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == '.')
				empties++;
				//empty.push_back(make_pair(i, j));
		}
		
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (isknown(i, j, field)) {
				known.push_back(make_pair(i, j));
				field[i][j] = ',';
			}

	while (!known.empty()) {
		pair<int, int> first = known.back();
		known.pop_back();
		if (isknown(first.first, first.second, field)) {
			empties -= 2;
			for (j = 0; j < 4; j++)
				if (!occ(first.first + offset[j][0], first.second + offset[j][1], field))
					break;
			pair<int, int> second = make_pair(first.first + offset[j][0], first.second + offset[j][1]);
			if (j == 0) {
				field[first.first][first.second] = '<';
				field[second.first][second.second] = '>';
			}
			if (j == 1) {
				field[first.first][first.second] = '^';
				field[second.first][second.second] = 'v';
			}
			if (j == 2) {
				field[first.first][first.second] = '>';
				field[second.first][second.second] = '<';
			}
			if (j == 3) {
				field[first.first][first.second] = 'v';
				field[second.first][second.second] = '^';
			}
			for (i = 0; i < 4; i++) {
				pair<int, int> third = make_pair(first.first + offset[i][0], first.second + offset[i][1]);
				if (isknown(third.first, third.second, field)) {
					known.push_back(third);
					field[third.first][third.second] = ',';
				}
			}
			for (i = 0; i < 4; i++) {
				pair<int, int> third = make_pair(second.first + offset[i][0], second.second + offset[i][1]);
				if (isknown(third.first, third.second, field) && (field[third.first][third.second] == '.')) {
					known.push_back(third);
					field[third.first][third.second] = ',';
				}
			}
		}
	}
	
	if (empties == 0) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				cout << field[i][j];
			cout << '\n';
		}
	}
	else
		cout << "Not unique";

	return 0;
}