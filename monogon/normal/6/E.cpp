
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, k;
int h[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int i = 0, j = 0;
    
    deque<int> qmin, qmax;
    qmin.push_back(0);
    qmax.push_back(0);
    int best = 0;
    while(j < n) {
        int dif = h[qmax.front()] - h[qmin.front()];
        if(dif <= k) {
            best = max(best, j - i + 1);
            j++;
            if(j < n) {
                while(qmax.size() && h[qmax.back()] <= h[j]) {
                    qmax.pop_back();
                }
                while(qmin.size() && h[qmin.back()] >= h[j]) {
                    qmin.pop_back();
                }
                qmax.push_back(j);
                qmin.push_back(j);
            }
        }else {
            if(qmax.front() == i) qmax.pop_front();
            if(qmin.front() == i) qmin.pop_front();
            i++;
        }
    }
    i = 0, j = 0;
    qmin.clear();
    qmax.clear();
    qmin.push_back(0);
    qmax.push_back(0);
    while(j < best - 1) {
        j++;
        while(qmax.size() && h[qmax.back()] <= h[j]) {
            qmax.pop_back();
        }
        while(qmin.size() && h[qmin.back()] >= h[j]) {
            qmin.pop_back();
        }
        qmax.push_back(j);
        qmin.push_back(j);
    }
    vector<int> v;
    while(j < n) {
        if(h[qmax.front()] - h[qmin.front()] <= k) {
            v.push_back(i);
        }
        if(qmax.front() == i) qmax.pop_front();
        if(qmin.front() == i) qmin.pop_front();
        i++;
        j++;
        if(j < n) {
            while(qmax.size() && h[qmax.back()] <= h[j]) {
                qmax.pop_back();
            }
            while(qmin.size() && h[qmin.back()] >= h[j]) {
                qmin.pop_back();
            }
            qmax.push_back(j);
            qmin.push_back(j);
        }
    }
    cout << best << " " << v.size() << endl;
    for(int x : v) {
        cout << x + 1 << " " << (x + best) << endl;
    }
}