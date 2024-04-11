#include <iostream>
#include <string>
#include <map>
using namespace std;

const int INF = 1000 * 1000 * 1000;

int main()
{
    ios_base::sync_with_stdio(0);
    map<string, int> cnt;
    
    cnt.insert(make_pair("void", 0));
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i)
    {
        string rub;
        cin >> rub;
        
        if(rub == "typeof")
        {
            string t;
            cin >> t;
            
            int j = 0, bal = 0;
            while(j < t.length() && t[j] == '&')
                --bal, ++j;
            j = t.length() - 1;
            while(j >= 0 && t[j] == '*')
                ++bal, --j;
            
            string sb = "";
            
            for(j = 0; j < t.length(); ++j)
                if(t[j] != '*' && t[j] != '&')
                    sb += t[j];
                    
            if(!cnt.count(sb) || cnt[sb] + bal < 0)
                cout << "errtype" << endl;
            else
            {
                cout << "void";
                for(int j = 0; j < cnt[sb] + bal; ++j)
                    cout << "*";
                cout << endl;
            }
        }
        else
        {
            int balance = 0;
            
            string t;
            cin >> t;
            
            string name;
            cin >> name;
            
            int j = 0;
            while(j < t.length() && t[j] == '&')
                --balance, ++j;
            j = t.length() - 1;
            while(j >= 0 && t[j] == '*')
                ++balance, --j;
            
            int curb = 0;
            string sb = "";
            
            for(j = 0; j < t.length(); ++j)
                if(t[j] != '*' && t[j] != '&')
                    sb += t[j];
                    
            if(cnt.count(sb))
                curb = cnt[sb];
            else
            {
                if(cnt.count(name))
                    cnt.erase(name);
                cnt.insert(make_pair(name, -INF));
                continue;
            }
            
            if(curb + balance >= 0)
            {  
                if(cnt.count(name))
                    cnt.erase(name);
                cnt.insert(make_pair(name, curb + balance));
            }
            else
            {
                if(cnt.count(name))
                    cnt.erase(name);
                cnt.insert(make_pair(name, -INF));
            }
        }
    }
    
    cin >> n;
    
    return 0;
};