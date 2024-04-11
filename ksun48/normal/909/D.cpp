#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string str;
    cin >> str;
    vector<pair<char,int> > f;

    for(int j = 0; j < (int)str.size(); j++){
        f.push_back(make_pair(str[j], 1));
    }
    int num = 0;
    while(1){
        vector<pair<char,int> > g;
        int smth = 0;
        for(int j = 0; j + 1 < (int)f.size(); j++){
            if(f[j].first != f[j+1].first){
                smth = 1;
                f[j].second --;
                f[j+1].second--;
            }
        }
        if(smth == 0) break;
        num++;

        for(int j = 0; j < (int)f.size(); j++){
            if(f[j].second <= 0) continue;
            g.push_back(f[j]);
        }
        f = g;

        g.clear();

        int cnt = 0;
        for(int j = 0; j < (int)f.size(); j++){
            cnt += f[j].second;
            if(j + 1 == (int)f.size() || f[j+1].first != f[j].first){
                g.push_back({f[j].first, cnt});
                cnt = 0;
            }
        }

        f = g;
    }
    cout << num << endl;
}