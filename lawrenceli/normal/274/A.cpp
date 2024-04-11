#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

const int MAXN = 100005;

typedef long long ll;

int n;
ll k;
int num;
vector<ll> v;
set<ll> s;
map<ll, int> m;
bool vis[MAXN];

int main() {
    cin >> n >> k;
    if (k==1) {
        cout << n << endl;
        return 0;
    }
    for (int i=0; i<n; i++) {
        ll a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        s.insert(v[i]);
        m[v[i]]=i;
    }
    for (int i=0; i<v.size(); i++) {
        if (vis[i]) continue;
        vis[i]=true;
        int n=1;
        ll j=v[i]*k;
        while (s.find(j)!=s.end()) {
            n++;
            vis[m[j]]=true;
            j*=k;
        }
        num+=(n+1)/2;
    }
    cout << num << endl;
}