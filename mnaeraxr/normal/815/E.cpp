#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

map<int64,int64> total(int64 size){
    map<int64,int64> answer;
    map<int64,int64> cur;
    cur[ size ] = 1;

    while (!cur.empty()){
        map<int64,int64> nxt;

        for (auto p : cur){
            answer[ (p.first + 1) / 2 ] += p.second;

            int64 a = (p.first - 1) / 2;
            int64 b = p.first - 1 - a;

            if (a > 0)
                nxt[ a ] += p.second;
            if (b > 0)
                nxt[ b ] += p.second;
        }

        cur.swap(nxt);
    }

    return  answer;
}

pair<int64,int64> check(map<int64,int64> &m, int64 d){
    int64 a = 0, b = 0;
    for (auto p : m){
        if (p.first == d)
            b = p.second;
        else if (p.first > d)
            a += p.second;
    }
    return {a, b};
}

int64 solve(int64 size, int64 k){
    if (k == 1)
        return (size + 1) / 2;

    auto answer = total( size );
    auto it = answer.rbegin();
    int64 nCount = 0;

    for (; it != answer.rend(); ++it){
        nCount += it->second;
        if (nCount >= k)
            break;
    }

    int64 dist = it->first;

    int64 a = (size - 1) / 2;
    int64 b = size - a - 1;

    auto left = total( a );
    auto right = total( b );

    auto L = check(left, dist);
    auto R = check(right, dist);
/*
    cout << size << " " << k << endl;
    cout << L.first << " " << L.second << endl;
    cout << R.first << " " << R.second << endl;
    cout << dist << endl;
    cout << endl;
*/
    if (k <= 1 + L.first + R.first + L.second){
        return solve(a, k - 1 - R.first);
    }
    else{
        return solve(b, k - L.first - L.second - 1) + (size + 1) / 2;
    }
}

int64 calc(int64 n, int64 k){
    if (k == 1){
        return 1;
    }
    else if (k == 2){
        return n;
    }

    n -= 2;
    k -= 2;

    return 1 + solve(n, k);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n, k;
    while (cin >> n >> k){
        cout << calc(n, k) << endl;
    }
    return 0;
}