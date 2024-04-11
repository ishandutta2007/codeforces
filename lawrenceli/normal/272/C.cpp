#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

typedef long long ll;

struct node {
    int r;
    ll h;
};

int n;
int m;
list<node> l;

int main() {
    //freopen("272C.in", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) {
        ll a;
        cin >> a;
        l.push_back((node){i, a});
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int w;
        ll h;
        cin >> w >> h;
        typeof(l.begin()) it1 = l.begin();
        typeof(l.begin()) it2 = l.begin();
        ll maxh=it1->h;
        while (it1!=l.end() && it1->r<w) {
            maxh=max(maxh, it1->h);
            it2=it1;
            it1++;
        }
        l.erase(l.begin(), it1);
        l.push_front((node){it2->r, maxh+h});
        cout << maxh << endl;
    }
}