#include <bits/stdc++.h>

using namespace std;

const int N = 200005, INF = 1e9;

int n;
int money[2];
vector<pair<int, int> > fountains[2];

int chooseBest(int type) {
    int ret = -INF;
    for (int i = 0; i < fountains[type].size(); i++) {
        if (fountains[type][i].first <= money[type]) {
            ret = max(ret, fountains[type][i].second);
        }
    }
    return ret;
}

int solveDiff() {
    int ansA = chooseBest(0);
    int ansB = chooseBest(1);
    return ansA + ansB;
}

int solveOne(int type) {
    int ret = -INF;
    int curId = 0;
    int bestId = -1;
    int secondBestId = -1;
    for (int i = fountains[type].size() - 1; i >= 0; i--) {
        int price = fountains[type][i].first;
        int beauty = fountains[type][i].second;
        while (curId < fountains[type].size() && fountains[type][curId].first + price <= money[type]) {
            if (bestId == -1 || fountains[type][curId].second > fountains[type][bestId].second) {
                secondBestId = bestId;
                bestId = curId;
            } else if (secondBestId == -1 || fountains[type][curId].second > fountains[type][secondBestId].second) {
                secondBestId = curId;
            }
            curId++;
        } 
        if (bestId != -1 && bestId != i) {
            ret = max(ret, beauty + fountains[type][bestId].second);
        } else if (secondBestId != -1) {
            ret = max(ret, beauty + fountains[type][secondBestId].second);
        }
    }
    return ret;
}

int main() {
  
    scanf("%d %d %d", &n, &money[0], &money[1]);
    
    for (int i = 1; i <= n; i++) {
        int be, pr;
        char type;
        scanf("%d %d %c", &be, &pr, &type);
        if (type == 'C') {
            fountains[0].push_back({pr, be});
        } else {
            fountains[1].push_back({pr, be});
        }
    }
    
    sort(fountains[0].begin(), fountains[0].end());
    sort(fountains[1].begin(), fountains[1].end());
    
    int ans = solveDiff();
    ans = max(ans, solveOne(0));
    ans = max(ans, solveOne(1));
    printf("%d\n", max(0, ans));
    
    return 0;
}