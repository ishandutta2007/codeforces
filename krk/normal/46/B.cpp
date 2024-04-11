#include <iostream>
#include <string>
#include <map>
using namespace std;

const int Maxs = 5;

string names[Maxs] = {"S", "M", "L", "XL", "XXL"};
map <string, int> conv;
int k, lft[Maxs];

int main()
{
    int i, j, rad;
    string s;
    for (i = 0; i < Maxs; i++) {
        cin >> lft[i];
        conv[names[i]] = i;
    }
    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> s;
        j = conv[s];
        rad = 0;
        while (true) {
              if (0 <= j + rad && j + rad < Maxs && lft[j+rad]) {
                    lft[j+rad]--;
                    break;
              } else if (rad <= 0) rad = -rad + 1;
                else rad = -rad;
        }
        cout << names[j+rad] << endl;
    }
    return 0;
}