#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int speed = 0;
    int hmovertake = 0;

    int answer = 0;

    stack<int> s;
    s.push(oo);

    for (int i = 0; i < n; ++i){
        int t; cin >> t;

        if (t == 1){
            cin >> speed;

            while (speed > s.top()){
                answer++;
                s.pop();
            }
        }
        else if (t == 2){
            answer += hmovertake;
            hmovertake = 0;
        }
        else if (t == 3){
            int maxspeed;
            cin >> maxspeed;
            s.push(maxspeed);
            while (speed > s.top())
            {
                answer++;
                s.pop();
            }
        }
        else if (t == 4){
            hmovertake = 0;
        }
        else if (t == 5){
            s.push(oo);
        }
        else if (t == 6){
            hmovertake++;
        }
        else
            assert(false);
    }

    cout << answer << endl;

    return 0;
}