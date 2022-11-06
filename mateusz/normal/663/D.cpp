#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

const int MAX_SCORE[] = {500, 1000, 1500, 2000, 2500, 3000};
const int COEFF[] = {2, 4, 8, 16, 32, 5000};
int maxPeople[6], minPeople[6];
int solved[3];

int n;
queue<int> tab[5][5];
int points[3][N];
int t[N];
bool wasHacked[N];
int ableToHack[3];

pair<int, int> calcSolved(int taskNo) {
    int maxSolved = 0, minSolved = 0;

    for (int i = 1; i <= n; i++) {
        if (points[taskNo][i] == 0) {
            continue;
        }
        maxSolved++;
        if (points[taskNo][i] > 0) {
            minSolved++;
        }
    }

    return make_pair(minSolved, maxSolved);
}

bool possible(vector<int> maxScores) {
    for (int i = 0; i < maxScores.size(); i++) {
        pair<int, int> solved = calcSolved(i);
        if (solved.second < minPeople[maxScores[i]] || solved.first > maxPeople[maxScores[i]]) {
            return false;
        }
    }
    return true;
}

vector<int> cmpVec;

int calcScore(int w) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        if (w == 1) {
             sum += 100 * (min(ableToHack[i], solved[i] - minPeople[cmpVec[i]]));
        }
        if (points[i][w] == 0) continue;
        sum += MAX_SCORE[cmpVec[i]] * (250 - abs(points[i][w])) / 250;
    }
    return sum;
}

bool cmp(int a, int b) {
    if (calcScore(a) == calcScore(b)) {
        return a < b;
    }
    return calcScore(a) > calcScore(b);
}

bool cmpWithMask(int w, int mask) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        if (points[i][w] > 0 || (points[i][w] < 0 && (mask & (1 << i)) == 0)) {
            sum += MAX_SCORE[cmpVec[i]] * (250 - abs(points[i][w])) / 250;
        }
    }
    return calcScore(1) >= sum;
}

int calcMask(int w) {
    int mask = 0;
    for (int i = 0; i < 8; i++) {
        if (cmpWithMask(w, i)) {
            mask |= (1 << i);
        }
    }
    return mask;
}

int getLower(int w) {
    if (w == 0) return 1;
    return 0;
}

int getHigher(int w) {
    if (w == 2) return 1;
    return 2;
}

int solve(vector<int> maxScores) {
    for (int i = 1; i <= n; i++) {
        t[i] = i;
    }
    cmpVec = maxScores;
    sort(t + 1, t + 1 + n, cmp);

    int myPos = 1;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 1) {
            myPos = i;
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            while (!tab[i][j].empty()) { tab[i][j].pop(); }
        }
    }
    for (int i = 1; i <= n; i++) {
        wasHacked[i] = false;
    }

    vector<int> last;
    int total = 0;
    for (int i = 1; i < myPos; i++) {
        int mask = calcMask(t[i]);
        if (mask == 0) {
            continue;
        }
        if (mask == (1 << 7)) {
            last.push_back(t[i]);
            continue;
        }
        total++;
        if (mask & 2) {
            tab[0][0].push(t[i]);
        } else if ((mask & 40) == 40) {
            tab[0][3].push(t[i]);
        } else if ((mask & 8)) {
            tab[0][1].push(t[i]);
        } else if ((mask & 32)) {
            tab[0][2].push(t[i]);
        }

        if (mask & 4) {
            tab[1][0].push(t[i]);
        } else if ((mask & 72) == 72) {
            tab[1][3].push(t[i]);
        } else if ((mask & 8)) {
            tab[1][1].push(t[i]);
        } else if ((mask & 64)) {
            tab[1][2].push(t[i]);
        }

        if (mask & 16) {
            tab[2][0].push(t[i]);
        } else if ((mask & 96) == 96) {
            tab[2][3].push(t[i]);
        } else if ((mask & 32)) {
            tab[2][1].push(t[i]);
        } else if ((mask & 64)) {
            tab[2][2].push(t[i]);
        }
    }
    int toHack[3];
    for (int i = 0; i < 3; i++) {
        toHack[i] = min(ableToHack[i], solved[i] - minPeople[maxScores[i]]);
    }
    priority_queue<pair<int, int> > Q;
    for (int i = 0; i < 3; i++) {
        bool p = false;
        for (int j = 0; j < 4; j++) if (!tab[i][j].empty()) p = true;
        if (p) {
            Q.push({toHack[i], i});
        }
    }

    int resPos = myPos;
    while (!Q.empty()) {
        int tmp = Q.top().first;
        int w = Q.top().second;
        Q.pop();
        if (tmp != toHack[w]) {
            if (toHack[w] > 0) {
                Q.push({toHack[w], w});
            }
            continue;
        }
        for (int j = 0; j < 4; j++) {
            int i;
            if (j == 0 || j == 3) {
                i = j;
            } else if (toHack[getLower(w)] < toHack[getHigher(w)]) {
                if (j == 2) i = 1;
                else i = 2;
            } else {
                i = j;
            }
            while (!tab[w][i].empty() && wasHacked[tab[w][i].front()]) {
                tab[w][i].pop();
            }
            if (!tab[w][i].empty()) {
                int u = tab[w][i].front();
                tab[w][i].pop();
                if (i == 1) {
                    if (toHack[getLower(w)] == 0) { continue; }
                    toHack[getLower(w)]--;
                }
                if (i == 2) {
                    if (toHack[getHigher(w)] == 0) continue;
                    toHack[getHigher(w)]--;
                }
                if (i == 3) {
                    if (toHack[getLower(w)] > toHack[getHigher(w)]) {

                        if (toHack[getLower(w)] == 0) continue;
                        toHack[getLower(w)]--;
                    } else {

                        if (toHack[getHigher(w)] == 0) continue;
                        toHack[getHigher(w)]--;
                    }
                }
                toHack[w]--;
                wasHacked[u] = true;
                resPos--;
                break;
            }
        }

        bool p = false;
        for (int j = 0; j < 4; j++) if (!tab[w][j].empty()) p = true;
        if (p && toHack[w] > 0) {
            Q.push({toHack[w], w});
        }
    }
    resPos -= min(min(min(toHack[0], toHack[1]), toHack[2]), (int)last.size());

    return resPos;
}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &points[0][i], &points[1][i], &points[2][i]);
        for (int j = 0; j < 3; j++) {
            if (points[j][i] != 0) solved[j]++;
            if (points[j][i] < 0) ableToHack[j]++;
        }
    }

    for (int i = 0; i < 6; i++) {
        if (i == 5) minPeople[i] = 0;
        else
        minPeople[i] = n / COEFF[i] + 1;
        maxPeople[i] = (i == 0 ? n : (n / COEFF[i - 1]));
    }

    int ans = n;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                vector<int> maxScores = {i, j, k};
                if (!possible(maxScores)) {
                    continue;
                }
                ans = min(ans, solve(maxScores));
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}