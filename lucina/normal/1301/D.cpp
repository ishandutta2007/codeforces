#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 +  10 ;
int n, m, k ;

vector< pair< int, string>> command;
void fin() {

    printf("%d\n", (int) command.size());
    for(auto & it : command) {
        printf("%d %s\n", it.first , it.second.c_str());
    }
    exit(0);
}

struct ans {
    int times;
    string s;
    ans () : times () , s () { }
    ans (int times, string s) : times (times) , s (s) {}
    void print () {
        if (k == 0) exit(0);
        if (times * ((int)s.size()) >= k) {
            while (times * ((int)s.size()) > k) {
                times -- ;
            }
            k -= times * (int)s.size();
            command.emplace_back(times, s);
            if (k == 0) fin();
            string ret ;
            for (int i = 0 ; i < k ; ++ i) {
                ret += s[i] ;
            }
            command.emplace_back(1, ret);
            k = 0;
            fin();
        }
        command.emplace_back(times, s);
        k -= (int)s.size() * times;
    }
};

int main () {
    scanf("%d %d %d", &n, &m, &k);

    if (k > (4 * m * n  - 2 * n - 2 * m))
        return !printf("NO");
    printf("YES\n");

    ans move_right = ans(m - 1, "R");
    ans move_left  = ans(m - 1, "L");
    ans move_up    = ans(n - 1, "U");
    ans move_down  = ans(n - 1 , "D");
    ans down       = ans(1, "D");
    ans right      = ans(1, "R");

    if (n == 1) {
        move_right.print();
        move_left.print();
    }
    if (m == 1) {
        move_down.print();
        move_up.print();
    }


    for (int i = 1 ; i < n ; ++ i) {
        move_right.print() ;
        move_left.print() ;
        down.print();
    }
    for (int j = 1 ; j < m ; ++ j) {
        right.print();
        move_up.print();
        move_down.print();
    }
    move_left.print();
    move_up.print();
   // fin();
}
/*
    Good Luck
        -Lucina
*/