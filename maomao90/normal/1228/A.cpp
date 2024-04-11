#include <iostream>
#include <string>
using namespace std;
 
bool nDiff(int num)
{
    string  str = to_string(num);
    bool flag = false;
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 0; j < str.size(); j++)
        {
            if (i == j)
            {
                continue;
            }
            if (str[i] == str[j])
            {
                flag = true;
                break;
            }
        }
    }
    return flag;
}
 
int main() {
    int l,r;
    cin >> l >> r;
    bool finded = false;
    for (int i = l; i <= r ; i++)
    {
        if (!nDiff(i))
        {
            cout << i << endl;
            finded = true;
            break;
        }
    }
    if (finded == false)
    {
        cout << -1 << endl;
    }
}