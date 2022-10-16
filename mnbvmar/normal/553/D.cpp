#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 100005;

struct Fraction {
    int p, q;
    Fraction(){}
    Fraction(int _p, int _q) : p(_p), q(_q) {}

    bool operator<(const Fraction& other) const {
        LL value1 = (LL)p * other.q,
           value2 = (LL)q * other.p;

        return (value1 < value2);
    }
};

Fraction values[MaxN];
int N, M, K;
vector<int> adj[MaxN];
bool isTaken[MaxN];
int numFree[MaxN];

void input(){
    scanf("%d%d%d", &N, &M, &K);
    for(int i = 0; i < K; i++){
        int v;
        scanf("%d", &v);
        isTaken[v] = true;
    }

    for(int i = 0; i < M; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main(){
    input();

    set<pair<Fraction,int>> cities;
    Fraction result(0,1);

    for(int city = 1; city <= N; city++){
        if(!isTaken[city]){
            int numNeigh = (int)adj[city].size();
            numFree[city] = 0;
            for(int s : adj[city]){
                if(!isTaken[s]) numFree[city]++;
            }

            cities.insert(make_pair(Fraction(numFree[city], numNeigh), city));
        }
    }

    vector<int> order;

    while(!cities.empty()){
        Fraction current;
        int cityNum;
        tie(current, cityNum) = *cities.begin();
//        printf("%d/%d\n", current.p, current.q);
        cities.erase(cities.begin());

        if(result < current){
//            printf("Y\n");
            order.clear();
            result = current;
        }
        order.push_back(cityNum);
        isTaken[cityNum] = true;

        for(int s : adj[cityNum]){
            if(isTaken[s]) continue;
            cities.erase(make_pair(Fraction(numFree[s], (int)adj[s].size()), s));
            numFree[s]--;
            cities.insert(make_pair(Fraction(numFree[s], (int)adj[s].size()), s));
        }
    }

    printf("%d\n", (int)order.size());
    for(int v : order) printf("%d ", v);
    printf("\n");


}