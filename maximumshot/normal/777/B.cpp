#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

pii simple(string a, string b) {
    sort(ALL(b));
    int res1 = inf;
    int res2 = 0;
    do{
        int tmp1 = 0;
        int tmp2 = 0;
        for(int i = 0;i < (int)a.size();i++) {
            if(a[i] < b[i]) {
                tmp2++;
            }else if(a[i] > b[i]) {
                tmp1++;
            }
        }
        res1 = min(res1, tmp1);
        res2 = max(res2, tmp2);
    }while(next_permutation(ALL(b)));
    return make_pair(res1, res2);
}

pii fast(string sa, string sb) {
    int res1 = 0;
    int res2 = 0;
    sort(ALL(sa));
    sort(ALL(sb));
    for(int j = 0, i = 0;i < (int)sa.size();i++) {
        while(j < (int)sb.size() && sb[j] < sa[i]) j++;
        if(j < (int)sb.size()) {
            j++;
        }else {
            res1 = (int)sa.size() - i;
            break;
        }
    }
    for(int j = 0, i = 0;i < (int)sa.size();i++) {
        while(j < (int)sb.size() && sb[j] <= sa[i]) j++;
        if(j < (int)sb.size()) {
            res2++;
            j++;
        }else {
            break;
        }
    }
    return make_pair(res1, res2);
}

void test() {
    int n = 10;
    while(1) {
        string a, b;
        a = b = "";
        for(int i = 0;i < n;i++) {
            a.push_back(rand() % 10 + '0');
            b.push_back(rand() % 10 + '0');
        }
        pii t1 = simple(a, b);
        pii t2 = fast(a, b);
        if(t1 != t2) {
            cout << "Wrong answer!\n";
            cout << "Expected : " << t1.first << " " << t1.second << "\n";
            cout << "Found : " << t2.first << " " << t2.second << "\n";
            cout << a << " " << b << "\n";
            break;
        }else {
            cout << "OK\n";
        }
    }
}

int main() {

//    test();

    int n;

    cin >> n;

    string a, b;

    cin >> a >> b;

//    pii t1 = simple(a, b);
    pii t2 = fast(a, b);

    cout << t2.first << "\n" << t2.second << "\n";

    return 0;
}