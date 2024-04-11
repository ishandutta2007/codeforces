#include <iostream>
#include <set>
using namespace std;
int main()
{
    char c;
    int n,p,i,t,b=-1,e=-1;
    set <int> s;
    set <int> :: iterator it;
    while (cin >> p)
    {
        cin >> c;
        s.insert(p);
    }
    for (it=s.begin();it!=s.end();it++)
    {
        t=*it;
        it++;
        if (*it==t+1)
        {
            if (b==-1)
            b=t;
            e=*it;
        }
        else
        {
            if (b==-1 && e==-1)
            {
                cout << t;
                if (it!=s.end())
                cout << ',';
            }
            else
            {
                cout << b << '-' << e;
                if (it!=s.end())
                cout << ',';
            }
            b=-1;
            e=-1;
        }
        it--;
    }
}