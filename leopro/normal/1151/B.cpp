/*
 * unsigned strlen(const char *str) {
    int len = 0;
    while (*str++) ++len;
    return len;
}

char *strcat(const char *str1, const char *str2, int new_size) {
    char *concat = new char[new_size];
    while (*concat++ = *str1++);
    --concat;
    *concat++ = '%';
    while (*concat++ = *str2++);
    return concat;
}

int strstr(const char *text, const char *pattern) {
    int new_size = strlen(pattern) + 1 + strlen(text) + 1;
    char *concat = strcat(pattern, text, new_size);
    int prefix[new_size];
    prefix[0] = 0;
    for (int i = 1; i < new_size; ++i) {
        int p = i - 1;
        while (p && concat[prefix[p]] != concat[i]) {
            p = prefix[p - 1];
        }
        prefix[i] = (concat[prefix[p]] == concat[i] ? prefix[p] + 1 : 0);
    }
    for (int i = strlen(pattern); i < new_size; ++i) {
        if (prefix[i] == strlen(pattern)) {
            return i - strlen(pattern) - 1 - strlen(pattern);
        }
    }
    return -1;
}
*/
#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<unsigned int>> matrix(n, vector<unsigned int>(m, 0));
    vector<set<unsigned int>> numbers(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
            numbers[i].insert(matrix[i][j]);
        }
    }
    unsigned int max_size = numbers[0].size();
    for (int i = 0; i < n; ++i) max_size = max(max_size, numbers[i].size());
    if (max_size == 1) {
        unsigned int XOR = 0;
        for (int i = 0; i < n; ++i) {
            XOR ^= matrix[i][0];
        }
        if (XOR == 0) {
            cout << "NIE\n";
            return 0;
        } else {
            cout << "TAK\n";
            for (int i = 0; i < n; ++i)cout << 1 << " ";
            return 0;
        }
    } else {
        unsigned int XOR = 0;
        int row = -1;
        int elem = -1;
        for (int i = 0; i < n; ++i) {
            XOR ^= matrix[i][0];
            if (numbers[i].size() > 1) {
                row = i;
                for (int j = 0; j < m; ++j) {
                    if (matrix[i][j] != matrix[i][0]) elem = j;
                }
            }
        }
        cerr << XOR << endl;
        if (XOR == 0) {
            cout << "TAK\n";
            for (int i = 0; i < n; ++i)cout << (i == row ? elem + 1 : 1) << " ";
            return 0;
        } else {
            cout << "TAK\n";
            for (int i = 0; i < n; ++i)cout << 1 << " ";
            return 0;
        }
    }
}