#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

const int Maxn = 50;
const int Maxp = 300;

int n;
bool prime[Maxp];
string num[Maxn];
vector <int> primes;

void Eratosten()
{
     fill(prime, prime+Maxp, true);
     for (int i = 2; i < Maxp; i++)
        for (int j = 2 * i; j < Maxp; j += i) prime[j] = false;
     for (int i = 2; i < Maxp; i++) 
        if (prime[i]) primes.push_back(i);
}

void Mult(string &num, int x)
{
     int extr = 0;
     for (int i = num.length() - 1; i >= 0; i--) {
         extr += x * int(num[i] - '0');
         num[i] = char(extr % 10 + '0');
         extr /= 10;
     }
     while (extr > 0) {
           stringstream s;
           string ss;
           s << char(extr % 10 + '0');
           s >> ss;
           num = ss + num;
           extr /= 10;
     }
}

int main()
{
    cin >> n;
    if (n == 2) cout << "-1\n";
    else {
         Eratosten();
         for (int i = 0; i < n; i++) num[i] = "1";
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < n; j++) if (j != i)
                Mult(num[j], primes[i]);
         }
         for (int i = 0; i < n; i++)
            cout << num[i] << endl;
    }
    return 0;
}