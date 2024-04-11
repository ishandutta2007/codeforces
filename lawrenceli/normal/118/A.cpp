#include <iostream>
using namespace std;

int main()
{
    string s1, s2="";
    cin >> s1;
    for (int i=s1.length()-1; i>=0; i--)
    {
        if (s1[i]=='A' || s1[i]=='O' || s1[i]=='Y' ||
            s1[i]=='U' || s1[i]=='E' || s1[i]=='I' ||
            s1[i]=='a' || s1[i]=='o' || s1[i]=='y' ||
            s1[i]=='u' || s1[i]=='e' || s1[i]=='i')
            s1.erase(s1.begin()+i);
    }
    for (int i=0; i<s1.length(); i++)
    {
        if (s1[i]<='Z') s1[i]=(char)((int)s1[i]-(int)'A'+(int)'a');
    }
    for (int i=0; i<s1.length(); i++)
    {
        s2+='.';
        s2+=s1[i];
    }
    cout << s2 << endl;
}