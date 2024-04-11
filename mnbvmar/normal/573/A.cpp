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
#define debug(...) {}
#endif

/////////////////////////////////////////////////////////


const int MaxN = 100005;

int N;
int tab[MaxN];

void input(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &tab[i]);
    }
}

int main(){
    input();

    for(int i = 0; i < N; i++){
        while(tab[i] % 2 == 0) tab[i] /= 2;
        while(tab[i] % 3 == 0) tab[i] /= 3;
    }

    if(count(tab, tab+N, tab[0]) == N){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}