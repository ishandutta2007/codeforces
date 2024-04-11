#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 5005;
const int Maxm = 2000;

int n;
bool w[Maxn];
int x[Maxn];
bool taken[Maxn];
vector <short> num;

void Mult()
{
     int car = 0;
     for (int i = 0; i < num.size(); i++) {
         car = 2 * num[i] + car;
         num[i] = car % 10; car /= 10;
     }
     if (car) num.push_back(car);
}

void Inc()
{
     int car = 1;
     for (int i = 0; i < num.size() && car; i++) {
         car = num[i] + car;
         num[i] = car % 10; car /= 10;
     }
     if (car) num.push_back(car);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        cin >> x[i];
        w[i] = s == "win";
    }
    num.push_back(0);
    int lst = Maxm + 1;
    for (int i = Maxm; i >= 0; i--) {
        int j;
        for (j = 0; j < n; j++)
            if (!w[j] && i == x[j]) break;
        if (j == n) continue;
        int l;
        for (l = j - 1; l >= 0 && !taken[l]; l--)
            if (w[l] && i == x[l]) break;
        if (l >= 0 && !taken[l]) {
              while (lst-- > i) Mult();
              Inc(); lst = i;
              for (; l <= j; l++) taken[l] = true;
        }
    }
    while (lst--) Mult();
    for (int i = num.size() - 1; i >= 0; i--) cout << num[i];
    cout << endl;
    return 0;
}