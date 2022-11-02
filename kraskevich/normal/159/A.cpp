#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, dt;
    cin >> n >> dt;
    map<pair<string, string>, vector<int> > mp;
    map<string, set<string> > s;
    set<string> temp;
    temp.clear();
    for(int i = 0; i < n; ++i) {
            string a, b;
            int t;
            cin >> a >> b >> t;
            vector<int> c;
            c.push_back(t);
            if(mp.count(make_pair(a, b)))
                                     mp[make_pair(a, b)].push_back(t);
            else
                mp.insert(make_pair(make_pair(a, b), c));
            for(int i = 0; i < mp[make_pair(b, a)].size() && mp.count(make_pair(b, a)); ++i) 
                if(mp.count(make_pair(b, a)) && t - mp[make_pair(b, a)][i] <= dt && t - mp[make_pair(b, a)][i] > 0) {
                                         if(s[b].count(a)) {}
                                         else {
                                             if(!s.count(a))
                                                            s.insert(make_pair(a, temp));
                                             s[a].insert(b);
                                             break;
                                         }
                }
    }
    int k = 0;
    map<string, set<string> >::iterator ii;
    for(ii = s.begin(); ii != s.end(); ++ii)
           k += ii->second.size();
    cout << k << endl;
    for(ii = s.begin(); ii != s.end(); ++ii) {
            set<string>::iterator ss;
            for(ss = ii->second.begin(); ss != ii->second.end(); ++ss)
                   cout << ii->first << " " << *ss << endl;
    }
    cin >> n;
    return 0;
}