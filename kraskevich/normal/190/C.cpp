#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

string s;
bool ok = true;
vector<bool> open(1000 * 1000, false);
vector<int> close(1000 * 1000, 0);
vector<bool> zp(1000 * 1000, false);
int last = -1;
int cnt = 0;


int go(int l)
{
    if(!ok)
           return -1;
    cnt++;
    last = max(last, l);
    if(l >= s.length())
    {
         ok = false;
         return -1;
    }
    if(s[l] == 'p')
    {
            open[l] = true;
            int cur = go(l + 1);
            if(cur == -1)
            {
                   ok = false;
                   return -1;
            }
            zp[cur] = true;
            int cur2 = go(cur + 1);
            if(cur2 == -1)
            {
                    ok = false;
                    return -1;
            }
            close[cur2]++;
            return cur2;
    }
    else
        return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    string cur;
    while(cin >> cur)
        if(cur == "int")
            s += 'i';
        else
            s += 'p';

    if(s == "i")
    {
         cout << "int" << endl;
         return 0;
    }    

    for(int i = 0; i < s.length(); ++i)
            if(i > last && s[i] == 'p')
                 go(i);

    if(cnt != s.length())
           ok = false;
           
    if(!ok)
           cout << "Error occurred";
    else
        for(int i = 0; i < s.length(); ++i)
        {
                if(s[i] == 'i')
                        cout << "int";
                if(s[i] == 'p')
                        cout << "pair";
                if(open[i])
                           cout << '<';
                for(int j = 0; j < close[i]; ++j)
                            cout << '>';
                if(zp[i])
                         cout << ",";
        }
    
    cout << endl;
   
    return 0;
}