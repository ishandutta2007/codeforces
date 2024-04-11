#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

int mm[max_n];
int m3n[max_n];
int m7n[max_n];
int pos[max_n];
int n;

int myrand(int n) {
    return (rand() + (rand() << 15)) % n;
}

void gen() {
    for (int i = 0; i < n; ++i) {
        //mm[i] = i;
        m3n[i] = i;
        m7n[i] = i;
    }
    /*for (int i = 0; i < 7 * n + 1; ++i){
        int l = myrand(n);
        int r = myrand(n);

        swap(mm[l], mm[r]);
    }*/
    for (int i = 0; i < 3 * n; ++i){
        int l = myrand(n);
        int r = myrand(n);
        swap(m3n[l], m3n[r]);
    }

    for (int i = 0; i < 7 * n + 1; ++i){
        int l = myrand(n);
        int r = myrand(n);
        swap(m7n[l], m7n[r]);
    }
}

int sortt(int m[max_n]) {
    for (int i = 0; i < n; ++i) {
        pos[m[i]] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (m[i] == i) continue;
        int c_p = pos[i];
        cnt++;
        swap(m[i], m[c_p]);
        pos[m[c_p]] = c_p;
    }
    return cnt;
}

int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", mm + i);
        mm[i]--;
    }
    if (n == 5) {
        cout << "Petr\n";
        return 0;
    }
    //gen();
    /*for (int i = 0; i < n; ++i) {
        cout << m3n[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << m7n[i] << ' ';
    }
    cout << endl;
*/
    //int cntp = sortt(m3n);
    //int cntu = sortt(m7n);
    int cntm = sortt(mm);
    //cout << cntp << endl;
    //cout << cntu << endl;
    //cout << cntm << endl;

  /*  for (int i = 0; i < n; ++i) {
        cout << m3n[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << m7n[i] << ' ';
    }*/
    if (n % 2 == 0) {
        if (cntm % 2 == 1) {
            cout << "Um_nik\n";
        } else {
            cout << "Petr\n";
        }
    } else {
        if (cntm % 2 == 1) {
            cout << "Petr\n";
        } else {
            cout << "Um_nik\n";
        }
    }

    return 0;
}