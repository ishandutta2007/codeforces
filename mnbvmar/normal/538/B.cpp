#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int N;
int result[10];

void input(){
	cin >> N;
}

int main(){
	input();

    int res = 0;
    for(int mul = 10000000; mul > 0; mul /= 10){
        int ptr = 0;
        while(N >= mul){
            result[ptr++] += mul;
            N -= mul;
            res = max(res, ptr);
        }
    }

    cout << res << endl;
    for(int i = 0; i < res; i++){
        cout << result[i] << " ";
    }
    cout << endl;
}