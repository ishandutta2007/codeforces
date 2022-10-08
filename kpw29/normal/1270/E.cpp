#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int n;
    cin>>n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i<n; i++) {cin>>p[i].first>>p[i].second; p[i].first+=1e6; p[i].second+=1e6;}
 
    while (true)
    {
        vector<vector<int>> cnt(2, vector<int>(2));
        for (int i = 0; i<n; i++) cnt[p[i].first%2][p[i].second%2]++;
        if (cnt[0][0]+cnt[1][1]>0 && cnt[0][1]+cnt[1][0]>0)
        {
            vector<int> A;
            for (int i = 0; i<n; i++) if ((p[i].first + p[i].second)%2==0) A.push_back(i);
            cout<<A.size()<<endl;
            for (auto it: A) cout<<it+1<<' ';
            return 0;
        }
        if (cnt[0][0]+cnt[0][1]>0 && cnt[1][1]+cnt[1][0]>0)
        {
            vector<int> A;
            for (int i = 0; i<n; i++) if (p[i].first%2==0) A.push_back(i);
            cout<<A.size()<<endl;
            for (auto it: A) cout<<it+1<<' ';
            return 0;
        }
        int x, y;
        for (int i = 0; i<2; i++)
            for (int j = 0; j<2; j++) if (cnt[i][j]>0) {x = i; y = j;}
 
        for (int i = 0; i<n; i++) {p[i].first = (p[i].first - x)/2; p[i].second = (p[i].second - y)/2;}
    }
 
}