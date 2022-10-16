#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif

/////////////////////////////////////////////////////////


const int M = 1000;
const int MaxN = 1000005;
const int MaxC = 1000005;

int N;
int px[MaxN], py[MaxN];
vector<int> bucks[MaxC/M + 10];

void input(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d%d", &px[i], &py[i]);
    }
}

int main(){
    input();
    for(int i = 0; i < N; i++){
        bucks[py[i]/M].push_back(i);
    }

    vector<int> order;
    for(int buck = 0; buck <= MaxC/M; buck++){
        sort(bucks[buck].begin(), bucks[buck].end(),
                [&](int lhs, int rhs){ return (px[lhs] < px[rhs]); });

        if(buck % 2 == 0){
            for(int v : bucks[buck]) order.push_back(v);
        } else {
            for(int i = (int)bucks[buck].size()-1; i >= 0; i--){
                order.push_back(bucks[buck][i]);
            }
        }
    }

    for(int v : order) printf("%d ", v+1);
    printf("\n");
}