#include <iostream>
using namespace std;

int main()
{
    string s;
    int num=0;
    cin >> s;
    for (int i=0; i<s.length(); i++)
        if (s[i]=='4' || s[i]=='7') num++;
    if (num==0)
    {
        cout << "NO" << endl;
        return 0;
    }
    while (num>0)
    {
        if (!(num%10==4 || num%10==7))
        {
            cout << "NO" << endl;
            return 0;
        }
        num/=10;
    }
    cout << "YES" << endl;
}