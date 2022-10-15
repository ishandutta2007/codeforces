#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

int len(const vector<bool> &x) {
    for (int i = x.size() - 1; i >= 0; --i) if (x[i] == 1) return i + 1;
    return 0;
}

void add_1(vector<bool> &x) {
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] == 1) x[i] = 0;
        else {
            x[i] = 1;
            break;
        }
    }
}

bool good(vector<bool> &x) {
    int L = len(x);
    for (int i = 0; i < L; ++i) {
        if (x[i] == 0) return false;
    }
    return true;
}

vector<bool> to_binary(int x) {
    vector<bool> result(20, 0);
    int i = 0;
    while (x) {
        result[i++] = x % 2;
        x /= 2;
    }
    return result;
}

int main() {
    int x;
    cin >> x;
    vector<bool> state = to_binary(x);
    int L = len(state);
    vector<int> ans(0);
    int count = 0;
    for (int i = L - 1; i >= 0; ++i) {
        if (good(state)) break;
        while (state[i] == 1) --i;
        ans.push_back(i + 1);
        for (int j = 0; j < i + 1; ++j) {
            state[j] = !state[j];
        }
        count++;
        if (!good(state)) add_1(state); else break;
        count++;
    }
    cout << count << endl;
    for (int a : ans){
        cout << a << " ";
    }
    return 0;
}