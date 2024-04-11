#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int Maxn = 11;
const string adrinks[Maxn] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", 
                              "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};

int main()
{
    int n, age, res = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if ('A' <= s[0] && s[0] <= 'Z') {
                for (int j = 0; j < Maxn; j++)
                   if (s == adrinks[j]) {
                         res++; break;
                   }
        } else {
               stringstream ss(s);
               ss >> age;
               if (age < 18) res++;
        }
    }
    cout << res << endl;
    return 0;
}