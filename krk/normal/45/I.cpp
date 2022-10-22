#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> neg;
int nils;
bool printed;

int main()
{
    cin >> n;
    while (n--) {
          int tmp; cin >> tmp;
          if (tmp > 0) {
                  if (printed) cout << " ";
                  cout << tmp; printed = true;
          } else if (tmp == 0) nils++;
          else neg.push_back(tmp);
    }
    sort(neg.begin(), neg.end());
    for (int i = 0; i + 1 < neg.size(); i += 2) {
        if (printed) cout << " ";
        cout << neg[i] << " " << neg[i + 1]; printed = true;
    }
    if (!printed) if (nils) cout << 0;
                  else cout << neg.back();
    cout << endl;
    return 0;
}