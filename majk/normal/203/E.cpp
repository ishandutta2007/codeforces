#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D, S; cin >> N >> D >> S;
    long long capacity = 0;
    int ducks = 0;
    vector<int> self;
    vector<int> carriers;
    for (int i = 0; i < N; i++) {
        int C, F, L; cin >> C >> F >> L;
        if (C == 0) {
            if (L >= D) {
                self.push_back(F);
            } else {   
                ducks++;
            }
        } else {
            capacity += C;
            if (L >= D) carriers.push_back(F);
        }
    }

    sort(carriers.begin(),carriers.end());
    int loFuelCarrier = carriers.empty() ? S+1 : carriers[0];
    for (int i = 1; i < carriers.size(); ++i) self.push_back(carriers[i]);
    sort(self.begin(),self.end());


    pair<int, int> ans = {0,S};
    if (loFuelCarrier <= S) {
        int cur = min((long long)N, capacity + 1);
        int spareFuel = S - loFuelCarrier;
        for (int s: self) {
            if (cur < N && s <= spareFuel) {
                cur++;
                spareFuel -= s;
            }
        }
        ans = {cur, spareFuel};
    } 

    {
        int cur = 0;
        int spareFuel = S;
        for (int s: self) {
            if (cur < N && s <= spareFuel) {
                cur++;
                spareFuel -= s;
            }
        }
        ans = max(ans, {cur, spareFuel});
    }



    cout << ans.first << ' ' << S-ans.second << '\n';
}