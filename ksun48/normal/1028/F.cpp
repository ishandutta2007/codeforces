#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<int,int> reduce(pair<int,int> x){
    int g = __gcd(x.first, x.second);
    return {x.first/g, x.second / g};
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0); 
    int q;
    cin >> q;
    map<pair<int,int>, int> ans;
    map<LL, vector<pair<int,int> > > distance_list;
    int num = 0;
    for(int i = 0; i < q; i++){
        int t;
        pair<int,int> x;
        cin >> t >> x.first >> x.second;
        LL d = LL(x.first) * LL(x.first) + LL(x.second) * LL(x.second);
        if(t == 1){
            vector<pair<int,int> >& r = distance_list[d];
            for(int i = 0; i < r.size(); i++){
                pair<int,int> y = r[i];
                ans[reduce({x.first + y.first, x.second + y.second})] += 2;
            }
            r.push_back(x);
            ans[reduce(x)]++;
            num++;
        } else if(t == 2){
            vector<pair<int,int> >& r = distance_list[d];
            for(int i = 0; i < r.size(); i++){
                pair<int,int> y = r[i];
                if(x == y){
                    r.erase(r.begin() + i);
                    break;
                }
            }
            for(int i = 0; i < r.size(); i++){
                pair<int,int> y = r[i];
                ans[reduce({x.first + y.first, x.second + y.second})] -= 2;
            }
            ans[reduce(x)]--;
            num--;
        } else if(t == 3){
            cout << num - ans[reduce(x)] << '\n';
        }
    }
}