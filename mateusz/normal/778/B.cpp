#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n, m;
string firstVarName, trash, val, val2, op, value[N];
map<string, int> ind;
int firstArg[N], secondArg[N];
int valPos[N];
bool isOp[N];
int opType[N];

int choose(string op) {
    if (op == "AND") {
        return 0;
    } else if (op == "OR") {
        return 1;
    } else {
        return 2;
    }
}

int getResult(int a, int b, int op) {
    if (op == 0) {
        return a & b;
    } else if (op == 1) {
        return a | b;
    } else {
        return a ^ b;
    }
}

int check(int pos, int x) {
    valPos[0] = x;
    for (int i = 1; i <= n; i++) {
        valPos[i] = 0;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (isOp[i] == false) {
            valPos[i] = value[i][pos] == '1' ? 1 : 0;
        } else {
            int firstBit = valPos[firstArg[i]];
            int secondBit = valPos[secondArg[i]];
            valPos[i] = getResult(firstBit, secondBit, opType[i]);
        }
        if (valPos[i]) {
            ret++;
        }
    }
    return ret;
}

int main() {
    
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    
    ind["?"] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> firstVarName >> trash >> val;
        ind[firstVarName] = i;
        if (!(val[0] >= '0' && val[0] <= '1')) {
            isOp[i] = true;
            cin >> op;
            cin >> val2;
            firstArg[i] = ind[val];
            secondArg[i] = ind[val2];
            opType[i] = choose(op);
        } else {
            value[i] = val;
        }
    }
    
    vector<int> best, worst;
    for (int i = 0; i < m; i++) {
        int ones = check(i, 1);
        int zeros = check(i, 0);
        if (ones > zeros) {
            best.push_back(1);
            worst.push_back(0);
        } else if (ones < zeros) {
            best.push_back(0);
            worst.push_back(1);
        } else {
            best.push_back(0);
            worst.push_back(0);
        }
    }
    
    for (int i = 0; i < worst.size(); i++) {
        cout << worst[i];
    }
    
    cout << endl;
    
    for (int i = 0; i < best.size(); i++) {
        cout << best[i];
    }
    return 0;
}