#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 200005;

int N;
pair<int,int> vals[MaxN];

void input(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &vals[i].first);
        vals[i].second = i;
    }
}

int main(){
    input();
    sort(vals, vals+N);

    set<pair<int,int>> intervals;
    intervals.insert(make_pair(-100,-100));
    intervals.insert(make_pair(10000000,100000000));

    int numUsed = 0;
    int lastSize = 0;
    for(int i = N-1; i >= 0; i--){
        numUsed++;
        int value = vals[i].first, pos = vals[i].second;
        auto it = intervals.lower_bound(make_pair(pos,-1e9));

        vector<pair<int,int>> toDel;
        int toInsertLeft = pos, toInsertRight = pos;
        if(it->first == pos+1){
            toInsertRight = it->second;
            toDel.emplace_back(it->first, it->second);
        }
        it--;
        if(it->second == pos-1){
            toInsertLeft = it->first;
            toDel.emplace_back(it->first, it->second);
        }

        int totSize = toInsertRight - toInsertLeft + 1;
        while(lastSize < totSize){
            printf("%d ", value);
            lastSize++;
        }

        for(auto P: toDel) intervals.erase(P);
        intervals.insert(make_pair(toInsertLeft, toInsertRight));
    }
    printf("\n");
}