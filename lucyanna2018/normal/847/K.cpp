#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int n, a, b, k, f;
map<string, int> mp;
int e[666][666];
vector<int> v;

int get_id(string s) {
    int sz = (int)mp.size();
    if (mp.find(s) != mp.end()) return mp[s];
    mp[s] = sz;
    return sz;
}

int main() {
    cin >> n >> a >> b >> k >> f;
    
    memset(e, 0, sizeof e);
    int last = -1;
    mp.clear();
    for(int i=0;i<n;i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int id1 = get_id(s1), id2 = get_id(s2);
        if(id1 == last) e[id1][id2] += b;
        else e[id1][id2] += a;
        last = id2;
    }
    
    v.clear();
    int N = (int)mp.size();	
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            v.push_back(e[i][j] + e[j][i]);
    sort(v.begin(), v.end());
    
    int ans = 0;
    for(int i=(int)v.size()-1;i>=0;i--) {
        int x = v[i];
        if(k>0 && x>f) {
            x=f; k--;
        }
        ans += x;
    }
    cout<<ans<<endl;
    
    return 0;
}