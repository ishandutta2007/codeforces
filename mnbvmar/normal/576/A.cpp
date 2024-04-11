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


int N;

void input(){
    scanf("%d", &N);
}

bool is_prime(int p){
    for(int i = 2; i*i <= p; i++){
        if(p % i == 0) return false;
    }
    return true;
}

int main(){
    input();
    vector<int> res;
    for(int p = 2; p <= N; p++){
        if(!is_prime(p)) continue;
        int q = p;
        while(q <= N){
            res.push_back(q);
            q *= p;
        }
    }
    printf("%d\n", (int)res.size());
    for(int v : res) printf("%d ", v);
    printf("\n");
}