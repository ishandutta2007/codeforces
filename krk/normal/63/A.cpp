#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> prior[4];

int main()
{
    int n;
    string a, b;
    cin >> n;
    while (n--) {
          cin >> a >> b;
          if (b == "rat") prior[0].push_back(a);
          else if (b == "woman" || b == "child") prior[1].push_back(a);
          else if (b == "man") prior[2].push_back(a);
          else prior[3].push_back(a);
    }
    for (int i = 0; i < 4; i++)
       for (int j = 0; j < prior[i].size(); j++)
          cout << prior[i][j] << endl;
    return 0;
}