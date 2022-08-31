#include <vector>
#include <iostream>
#include <array>
using namespace std;
typedef long long LL;


void SpezzaCifre(LL N, vector<int>& vecN) {
    while (N != 0) {
        vecN.push_back(N%10);
        N /= 10;
    }
}

vector<int> vecL, vecR;
int cc = 0;

vector<int> nines(20, 9);
vector<int> zeroes(20, 0);

bool Doable(int m, const vector<int>& a, const vector<int>& b, array<int, 10>& is) {
    if (m == 0) return true;
    
    m--;
    int ca = a[m], cb = b[m];
    for (int c = ca + 1; c < cb; c++) {
        if (is[c] > 0) return true;
    }

    if (ca == cb) {
        if (is[ca] == 0) return false;
        is[ca]--;
        bool possible = Doable(m, a, b, is);
        is[ca]++;
        return possible;
    }
    
    if (is[ca] > 0) {
        is[ca]--;
        if (Doable(m, a, nines, is)) return true;
        is[ca]++;
    }
    
    if (is[cb] > 0) {
        is[cb]--;
        if (Doable(m, zeroes, b, is)) return true;
        is[cb]++;
    }
    return false;
}

void CreateIncreasingSubseq(int c, int s, array<int, 10>& is) {
    if (c == 9) {
        is[c] = s;
        auto at_is = is;
        if (Doable(vecL.size(), vecL, vecR, at_is)) cc++;
        return;
    }
    for (int i = 0; i <= s; i++) {
        is[c] = i;
        CreateIncreasingSubseq(c + 1, s - i, is);
    }
}

int main() {
    ios::sync_with_stdio(false);

    LL L, R;
    cin >> L >> R;
    SpezzaCifre(L, vecL);
    SpezzaCifre(R, vecR);
    while (vecL.size() < vecR.size()) vecL.push_back(0);

    array<int, 10> is = {};
    CreateIncreasingSubseq(0, vecR.size(), is);

    cout << cc << "\n";
}