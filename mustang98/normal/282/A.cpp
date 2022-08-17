#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a=0, n;
    string s;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>s;
        if (s[0]=='-' || s[2]=='-') a--;
        else a++;
    }
    cout<<a;
    return 0;
}