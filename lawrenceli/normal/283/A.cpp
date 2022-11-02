#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 200005;

int n;
long long sum, last;
long long dif[MAXN]; //a[i+1]-a[i]
vector<int> v;

int main() {
    cin >> n;
    v.push_back(0);
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;
        if (t==1) {
            int a, x;
            cin >> a >> x;
            sum+=x*a;
            if (a==v.size()) last+=x;
            else dif[a-1]-=x;
        }
        else if (t==2) {
            int k;
            cin >> k;
            v.push_back(k);
            dif[v.size()-2]=k-last;
            last = k;
            sum+=k;
        }
        else {
            sum-=last;
            last = last-dif[v.size()-2];
            v.pop_back();
        }
        cout << setprecision(7) << (double)sum/v.size() << endl;
    }
}