#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200100;
const int INF = 1e9 + MAXN;

int n, k, a[MAXN];

int main() {
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        if (s == "?") a[i] = INF;
        else {
            stringstream ss (s);
            ss >> a[i];
        }
    }
        
    for (int i=0; i<k; i++) {
        int last = -INF, num = 0;
        for (int j=i; j<n+k; j+=k)
            if (a[j] != INF) {
                if (j>=n) a[j] = INF;
                if (a[j]-last <= num) {
                    cout << "Incorrect sequence";
                    return 0;
                }
                vector<int> v;
                if (a[j]<=0) {
                    for (int i1=a[j]-1; i1>=a[j]-num; i1--) v.push_back(i1);
                } else if (last>=0) {
                    for (int i1=last+1; i1<=last+num; i1++) v.push_back(i1);
                } else {
                    int l = -1, r = 0;
                    for (int i1=0; i1<num; i1++) {
                        if (abs(l)<abs(r) && l>last || r==a[j]) v.push_back(l), l--;
                        else v.push_back(r), r++;
                    }
                }
                
                sort(v.begin(), v.end());
                for (int i1=0; i1<v.size(); i1++)
                    a[j-k*(num-i1)] = v[i1];
                
                last = a[j];
                num = 0;
            } else num++;
    }
    
    for (int i=0; i<n; i++) cout << a[i] << ' ';
}