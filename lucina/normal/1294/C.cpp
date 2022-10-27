#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
#define no {printf("NO\n");return;}
void solve(){
    int n, a = -1, b = -1, c = -1;
    cin >> n;
    int g = sqrt(n);
    for(int i = 2  ;i <= g ; i ++){
        if(n % i == 0){
            a = i;
            n /= i;
            break;
        }
    }
    if(a == -1) no ;
    g = sqrt(n);
    for(int i = 2 ;i <= g ;i ++){
        if(n % i == 0){
            set<int> setik;
            setik.insert(a);
            setik.insert(b = i);
            setik.insert(c = n / i);
            if((int)setik.size() == 3){
                printf("YES\n%d %d %d\n", a, b, c);
                return ;
            }
        }
    }
    no;
}
int main(){
    int T;
    for(cin >> T ; T -- ;){
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/