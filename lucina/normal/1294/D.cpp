#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;
int q, x;
map<int, int > ss;

void ins(int a){
    ss[a] ++;
}
void del(int a){
    ss[a] --;
    if(ss[a] == 0)
        ss.erase(ss.find(a));
}

int main(){
    scanf("%d %d", &q, &x);
    int cmp = 0, tot = 0, want = 0;
    multiset<int> wait;
    for(; q -- ; ){
        int y;
        scanf("%d", &y);
        y %= x;
        wait.insert(y);
        while(!wait.empty() &&  wait.count(want)){
            want ++;
            wait.erase(wait.find(want - 1));
            if(want == x) want = 0, tot ++;
        }
      //  cerr << "ANS = ";
        printf("%lld\n", 1LL * tot * x + want);
    }
}
/*
    Good Luck
        -Lucina
*/