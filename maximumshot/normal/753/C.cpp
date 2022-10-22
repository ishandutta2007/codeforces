#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;

string itoa(int x) {
    string s = "";
    for(int i = 0;i < 4;i++) {
        s.push_back(x % 10 + '0');
        x /= 10;
    }
    reverse(ALL(s));
    return s;
}

bool check(int x) {
    vec< char > used(10);
    for(int i = 0;i < 4;i++) {
        if(used[x % 10]) {
            return 0;
        }
        used[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

pii get(string a, string b) {
    int x = 0;
    int y = 0;
    for(int i = 0;i < 4;i++) {
        if(a[i] == b[i]) {
            x++;
            continue;
        }
        for(int j = 0;j < 4;j++) {
            if(a[i] == b[j]) {
                y++;
                break;
            }
        }

    }
    return make_pair(x, y);
}

int main() {

    srand(2333333);

    vec< string > mas, tmp;
    for(int i = 0;i < 10000;i++) {
        if(check(i)) {
            mas.push_back( itoa(i) );
        }
    }

    while(1) {
        random_shuffle(ALL(mas));
        cout << mas[0] << endl;
        int x, y;
        cin >> x >> y;
        if(x == 4 && y == 0) {
            break;
        }
        tmp.clear();
        for(int i = 1;i < (int)mas.size();i++) {
            if( make_pair(x, y) == get(mas[0], mas[i]) ) {
                tmp.push_back( mas[i] );
            }
        }
        mas = tmp;
    }

    return 0;
}