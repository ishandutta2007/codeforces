#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef long long LL;

int M;
int H[2], A[2], X[2], Y[2];


void input(){
    cin >> M;
    for(int i = 0; i < 2; i++){
        cin >> H[i] >> A[i] >> X[i] >> Y[i];
    }
}


pair<int,int> get_time(int h, int a, int x, int y){
    int nh = h;
    int res = -1;
    for(int i = 1; i <= 2*M; i++){
        h = ((LL)h * x + y) % M;
        if(h == a && res != -1)
            return make_pair(res, i - res);
        if(h == a && res == -1) res = i;
    }
    return make_pair(res, -1);
}

#undef int
int main(){
#define int long long
    input();

    auto v1 = get_time(H[0], A[0], X[0], Y[0]),
         v2 = get_time(H[1], A[1], X[1], Y[1]);


    if(v1.first == -1 || v2.first == -1){
        cout << -1 << endl;
        return 0;
    }
    if(v1.second == -1 || v2.second == -1){
        int result = -1;
        if(v1.first == v2.first) result = v1.first;
        if(v1.second != -1 && v2.first%v1.second == v1.first%v1.second && v2.first >= v1.first) result = v2.first;
        if(v2.second != -1 && v1.first%v2.second == v2.first%v2.second && v1.first >= v2.first) result = v1.first;

        cout << result << endl;
        return 0;
    }

    LL result = v1.first;
    for(int i = 0; i <= 2*M; i++){
        if(result >= v2.first && result % v2.second == v2.first % v2.second){
            cout << result << endl;
            return 0;
        }
        result += v1.second;
    }
    cout << -1 << endl;
    return 0;
    
}