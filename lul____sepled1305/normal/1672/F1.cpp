#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

string ss[2] = {"NO","YES"};

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n];
        int b[n];
        vector<int> pos[n+1];
        for(int i=0;i<n;i++) {
            cin>>a[i];
            pos[a[i]].push_back(i);
        }
//        cout<<"YEAH\n";
        vector<pii> v;
        for(int i=0;i<=n;i++) {
            if(pos[i].size() > 0)
                v.push_back({pos[i].size(),i});
        }
        sort(v.begin(),v.end(), greater<pii>());
//        cout<<"WOW\n";
        while(!v.empty()) {
//            cout<<v.size()<<endl;
//            for(auto it: v)
//                cout<<it.first<<' '<<it.second<<endl;
            for(int i=1;i<v.size();i++) {
                b[pos[v[i].second].back()] = v[i-1].second;
                v[i].first--;
                pos[v[i].second].pop_back();
            }
            v[0].first--;
            b[pos[v[0].second].back()] = v[v.size()-1].second;
            pos[v[0].second].pop_back();
            while(!v.empty() && v.back().first == 0) {
                v.pop_back();
            }
        }
        for(int i=0;i<n;i++) {
            cout<<b[i]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}