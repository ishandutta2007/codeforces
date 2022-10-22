#include <bits/stdc++.h>
using namespace std;

const int Maxl = 26;

int n;
string a, b;
vector <int> seq;

int main()
{
    cin >> n;
    cin >> a;
    cin >> b;
    int car = 0;
    for (int i = n - 1; i >= 0; i--) {
        car += int(a[i] - 'a') + int(b[i] - 'a');
        seq.push_back(car % Maxl);
        car /= Maxl;
    }
    while (car) {
        seq.push_back(car % Maxl);
        car /= Maxl;
    }
    car = 0;
    for (int i = int(seq.size()) - 1; i >= 0; i--) {
        car = car * Maxl + seq[i];
        seq[i] = car / 2;
        car %= 2;
    }
    for (int i = n - 1; i >= 0; i--)
        printf("%c", seq[i] + 'a');
    printf("\n");
    return 0;
}