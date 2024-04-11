#include <iostream>
#include <string>
typedef long long lli; 
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if (s1.length()!=s2.length())
        cout<<"NO";
    else 
    {
        char x,y;
        bool e=true;
        bool c=true;
        for (int i=0;i<s1.length();i++)
            if(s1[i]!=s2[i])
            {
                if (e)
                {
                    x=s1[i];
                y=s2[i];
                e=false;
                }
                else
                {
                    if (s1[i]!=y || s2[i]!=x) {cout<<"NO"; return 0;}
                    else
                    if (c) c=false;
                    else {cout<<"NO"; return 0;}
                }
            }
    if (c) cout<<"NO"; else cout<<"YES";
    }
    return 0;
}