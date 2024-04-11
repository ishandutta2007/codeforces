#include <iostream>
#include <string>
#include <map>
using namespace std;

map <string, int> id;
string m[12];

int main()
{
    m[0] = "January"; m[1] = "February"; m[2] = "March"; m[3] = "April";
    m[4] = "May"; m[5] = "June"; m[6] = "July"; m[7] = "August";
    m[8] = "September"; m[9] = "October"; m[10] = "November"; m[11] = "December";
    for (int i = 0; i < 12; i++) id[m[i]] = i;
    string s;
    int k;
    cin >> s >> k;
    cout << m[(id[s]+k)%12] << endl;
    return 0;
}