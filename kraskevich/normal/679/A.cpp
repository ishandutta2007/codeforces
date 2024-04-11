#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const string YES = "yes";
const string PR = "prime";
const string CO = "composite";

bool isPrime(int n) {
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

bool check(int x) {
    cout << x << endl;
    cout.flush();
    string s;
    cin >> s;
    return s == YES;
}

int main() {
    ios_base::sync_with_stdio(0);
    bool prime = true;
    int p = -1;
    for (int i = 2; i <= 10; i++) 
        if (isPrime(i) && check(i)) {
            p = i;
            break;
        }
    if (p == -1) {
        cout << PR << endl;
        cout.flush();
        return 0;
    }
    for (int i = p; i * p <= 100; i++)
        if (isPrime(i) && check(i * p)) {
            cout << CO << endl;
            cout.flush();
            return 0;
        }
    cout << PR << endl;
    cout.flush();     
    return 0;
}