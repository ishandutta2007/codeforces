#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;

const int inf = 1e9;
const ll inf64 = 1e18;

// u / v
ll myCeil(ll u, ll v) {
    if (u >= 0) {
        return u % v ? u / v + 1 : u / v;
    } else {
        return u / v;
    }
}

int timer = 0;
struct Node {
    ll d, v, k, pos;
    int id;
    Node() {
        d = v = k = pos = id = 0;
    }
    bool operator < (const Node &o) const {
        return make_pair(v, id) < make_pair(o.v, o.id);
    }
    bool operator == (const Node &o) const {
        return make_pair(v, id) == make_pair(o.v, o.id);
    }
};

ll LAST;
ll a1 = 0;
ll J1 = 1;
ll sumS = 0;
ll sumD = 0;
ll sumK = 0;
set<Node> qv; // {d, v, j}
unordered_map<ll, Node> mp;
ll acc = 0;

void show() {
    vector<Node> arr;
    for (Node x : qv) {
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(), [&](Node lx, Node rx){
        return lx.pos < rx.pos;
    });
    cout << "\n------\n";
    cout << "a1=" << a1 << ",J1=" << J1 << "\n";
    for (Node x : arr) {
        cout << "(";
        cout << "d=" << x.d + sumS * x.k << ",";
        cout << "k=" << x.k << ",";
        cout << "v=" << x.v - sumS << ")\n";
    }
    cout << "\n";
}

void refresh(ll s) {
    while ((int)qv.size() > 0 && qv.begin()->v - sumS <= 0) {
        Node x = *qv.begin();
        qv.erase(qv.begin());
        ll POS = x.pos + x.k;
        if (POS == sumK + J1) { // last
            sumD -= x.d;
            sumK -= x.k;
            mp.erase(x.pos);
            LAST += x.k;
            continue;
        }
        Node y = mp[POS];
        mp.erase(x.pos);
        mp.erase(y.pos);
        qv.erase(y);
        Node z;

        z.pos = x.pos;
        z.d = x.d + y.d;
        z.k = x.k + y.k;
        z.v = myCeil(-(z.d + sumS * z.k), z.k) + sumS;
        z.id = timer++;

        qv.insert(z);
        mp[z.pos] = z;
    }
}

void update(int b, int s) {
    acc += s;
    a1 += b;
    sumS += s;
    refresh(s);
}

void addHead(int k) {
    Node leftNode;
    leftNode.d = a1 - 0 - sumS * k;
    leftNode.k = k;
    leftNode.v = myCeil(-(leftNode.d + sumS * leftNode.k), leftNode.k) + sumS;
    leftNode.pos = J1 - k;
    leftNode.id = timer++;

    mp[leftNode.pos] = leftNode;

    sumD += leftNode.d;
    sumK += leftNode.k;

    a1 = 0;
    J1 -= k;

    qv.insert(leftNode);

    acc = 0;

    update(0, 0);
}

pll query() {
    return make_pair(
        sumK + 1,
        a1 + sumD + sumS * sumK
    );
}

void addTail(int k) {
    Node rightNode;
    rightNode.k = LAST;
    rightNode.d = 0 - query().second - sumS * rightNode.k;
    rightNode.pos = sumK + J1;
    rightNode.v = myCeil(-(rightNode.d + sumS * rightNode.k), rightNode.k) + sumS;
    rightNode.id = timer++;

    mp[rightNode.pos] = rightNode;

    sumD += rightNode.d;
    sumK += rightNode.k;

    qv.insert(rightNode);

    LAST = k;

    update(0, 0);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> LAST >> m;

    for (int iter = 0; iter < m; iter++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            cin >> k;
            addHead(k);
        } else if (type == 2) {
            int k;
            cin >> k;
            addTail(k);
        } else if (type == 3) {
            int b, s;
            cin >> b >> s;
            update(b, s);
        }
//        show();
        pll result = query();
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}