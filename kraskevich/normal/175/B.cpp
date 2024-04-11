#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

string type(int up, int down, int all)
{
       if(down * 100 >= 99 * all)
               return "pro";
       if(down * 100 >= 90 * all)
               return "hardcore";
       if(down * 100 >= 80 * all)
               return "average";
       if(down * 100 >= 50 * all)
               return "random";
       return "noob";
}
       
int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    map<string, int> pl;
    
    for(int i = 0; i < n; ++i)
    {
            int t;
            string s;
            cin >> s >> t;
            if(pl.count(s))
                           pl[s] = max(pl[s], t);
            else
                pl.insert(make_pair(s, t));
    }
    
    vector<int> p;
    vector<string> name;
    
    for(map<string, int>::iterator ii = pl.begin(); ii != pl.end(); ++ii)
                    name.push_back(ii->first), p.push_back(ii->second);
    
    int all = name.size();
    
    cout << all << endl;
    
    for(int i = 0; i < all; ++i)
    {
            int down = 0, up = 0;
            for(int j = 0; j < all; ++j)
                         if(p[j] <= p[i])
                                 down++;
                         else
                             up++;
            cout << name[i] << " " << type(up, down, all) << endl;
    }
    
    cin >> n;
    return 0;
}