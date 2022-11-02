#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
long long num;
vector<int> v;
map<int, int> m;

int f(int x) {
    if (x==0) return 0;
    if (x%2==0) return f(x/2);
    return f((x-1)/2)+1;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x; v.push_back(f(x));
    }
    for (int i=0; i<n; i++) m[v[i]]++;
    for (typeof(m.begin()) it=m.begin(); it!=m.end(); it++) {
        num+=(long long)it->second*(it->second-1)/2;
    }
    cout << num << endl;
}