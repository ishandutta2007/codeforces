#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int n, k;
int a[N][3];

struct BIT{
    vector<int> coor;
    vector<int> a;

    void addCoor(int x) {
        coor.push_back(x);
    }
    void finalize() {
        sort(coor.begin(), coor.end());
        int n = unique(coor.begin(), coor.end()) - coor.begin();
        coor.resize(n);
        a.resize(n + 1);
    }
    void add(int x, int val) {
        int pos = lower_bound(coor.begin(), coor.end(), x) - coor.begin();
        assert(coor[pos] == x); 
        pos++;
        while (pos < a.size()) {
            a[pos] += val;
            pos += pos & -pos;
        }
    }
    int get(int x) {
        int pos = upper_bound(coor.begin(), coor.end(), x) - coor.begin();
        int ans = 0;
        while (pos) {
            ans += a[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
    int getRange(int L, int R) {
        return get(R) - get(L);
    }
};

BIT mBit[N];
vector<int> coorEvent, IQ;
vector<int> event[N];
vector<int> desEvent[N];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 3; j++) cin >> a[i][j];
    for(int i = 1; i <= n; i++) {
        coorEvent.push_back(a[i][0]);
        coorEvent.push_back(a[i][0] + a[i][1] + 1);
        IQ.push_back(a[i][2]);
    }
    sort(IQ.begin(), IQ.end());
    int tmp = unique(IQ.begin(), IQ.end()) - IQ.begin(); 
    IQ.resize(tmp);

    sort(coorEvent.begin(), coorEvent.end());
    tmp = unique(coorEvent.begin(), coorEvent.end()) - coorEvent.begin(); 
    coorEvent.resize(tmp);

    for(int i = 1; i <= n; i++) {
        int pos = lower_bound(coorEvent.begin(), coorEvent.end(), a[i][0]) 
            - coorEvent.begin();
        event[pos].push_back(i);

        int pos2 = lower_bound(coorEvent.begin(), coorEvent.end(), a[i][0] + a[i][1] + 1) - coorEvent.begin();
        desEvent[pos2].push_back(i);

        a[i][2] = lower_bound(IQ.begin(), IQ.end(), a[i][2]) - IQ.begin();
        mBit[a[i][2]].addCoor(a[i][0]);
    }
    for(int i = 0; i < IQ.size(); i++)
        mBit[i].finalize();

    long long ans = 0;
    for(int j = 0; j < coorEvent.size(); j++) {
        for(auto i : desEvent[j]) {
            int pack = a[i][2];
            mBit[pack].add(a[i][0], -1);
        }
        for(auto i : event[j]) {
            int pack = a[i][2];
            int L = a[i][0] - a[i][1] - 1, R = a[i][0];
            //cout << L << " " << R << '\n'; 
            ans += mBit[pack].getRange(L, R);
            
            for(int i1 = pack - 1; i1 >= 0; i1--) {
                if (IQ[pack] - IQ[i1] > k) break;
                ans += mBit[i1].getRange(L, R);
            }
            for(int i1 = pack + 1; i1 < IQ.size(); i1++) {
                if (IQ[i1] - IQ[pack] > k) break;
                ans += mBit[i1].getRange(L, R);
            }
            mBit[pack].add(a[i][0], 1);
        }
    }
    cout << ans;
}