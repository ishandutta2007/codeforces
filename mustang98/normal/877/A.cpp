#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 1, inf = 1000111222;
string s;
string names[] = {
    "Danil",
    "Olya",
    "Slava",
    "Ann",
    "Nikita"
};

bool check(int from, string name) {
    for (int i = 0; i < name.size(); ++i) {
        if (from + i >= s.size() || s[from + i] != name[i]) return false;
    }
    return true;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 5; ++j) {
            if (check(i, names[j])) ++cnt;
        }
    }
    if (cnt == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}