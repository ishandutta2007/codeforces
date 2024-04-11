#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

string new_pass;
string other_pass;

char to_lower(char a) {
    if (a >= 'A' && a <= 'Z') {
        a = a - 'A' + 'a';
    }
    return a;
}

bool letters_eqv(char l1, char l2) {
    l1 = to_lower(l1);
    l2 = to_lower(l2);
    if ((l1 == l2) ||
        (l1 == '0' && l2 == 'o') ||
        (l1 == 'o' && l2 == '0') ||
        (l1 == '1' && l2 == 'i') ||
        (l1 == 'i' && l2 == '1') ||
        (l1 == '1' && l2 == 'l') ||
        (l1 == 'l' && l2 == '1') ||
        (l1 == 'l' && l2 == 'i') ||
        (l1 == 'i' && l2 == 'l')) {
            return true;
        }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> new_pass;
    int cnt_old;
    cin >> cnt_old;

    while (cnt_old--) {
        cin >> other_pass;
        if (new_pass.size() != other_pass.size()) {
            continue;
        }
        int cnt_eqv = 0;
        for (int i = 0; i < new_pass.size(); ++i) {
            if (letters_eqv(new_pass[i], other_pass[i])) {
                ++cnt_eqv;
            }
        }
        if (cnt_eqv == new_pass.size()) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}