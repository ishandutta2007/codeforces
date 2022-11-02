#include <bits/stdc++.h>

using namespace std;

const int N = 600;
const int LINE_WIDTH = 3;

int rows, cols;
int f[N][N];

double avg(int r, int c) {
    double sum = 0;
    for (int i = c; i < c + LINE_WIDTH; i++)
        sum += f[r][i];
    return sum / LINE_WIDTH;
}

double sqr(double a) {
    return a * a;
}

double getDist(int r1, int r2) {
    vector<double> av1(cols);
    vector<double> av2(cols);
    for (int i = 0; i < cols; i++) {
        av1[i] = avg(r1, i);
        av2[i] = avg(r2, i);
    }
    double res = 0;
    for (int i = 0; i < cols; i++)
        res += sqr(av1[i] - av2[i]);
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        cin >> rows >> cols;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> f[i][j];
        double dSwap = getDist(0, rows - LINE_WIDTH);
        double dStay = getDist(rows / 2 - LINE_WIDTH, rows / 2);
        if (dStay < dSwap)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;    
}