#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, a[10010];


// vector<int> A = {0, 1, 6, 4, 2, 3, 5, 4};

// int OR(int x, int y){
//     return A[x] | A[y];
// }

// int AND(int x, int y){
//     return A[x] & A[y];
// }


int OR(int x, int y){
    cout << "or " << x << " " << y << "\n";
    cout.flush();

    int re; cin >> re;
    return re;
}

int AND(int x, int y){
    cout << "and " << x << " " << y << "\n";
    cout.flush();

    int re; cin >> re;
    return re;
}

void answer(int x){
    cout << "finish " << x << "\n";
    cout.flush();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;

    for(int i=1;i<=1;i++){
        int A[3] = {i, i+1, i+2};
        if(A[1] > n) A[1] -= n;
        if(A[2] > n) A[2] -= n;

        int B[3], C[3];
        for(int i=0;i<3;i++) B[i] = OR(A[i], A[(i+1)%3]);
        for(int i=0;i<3;i++) C[i] = AND(A[i], A[(i+1)%3]);

        for(int i=0;i<3;i++) a[A[i]] = C[i] | C[(i+2)%3];
        for(int i=0;i<3;i++){
            for(int j=0;j<30;j++) if(((1 << j) & B[i]) && !((1 << j) & C[i])){
                int k = (1 << j);
                if((a[A[i]] & k) || (a[A[(i+1)%3]] & k)) continue;

                if(B[(i+1)%3] & k) a[A[(i+1)%3]] += k;
                else a[A[i]] += k;
            }
        }
    }

    for(int i=4;i<=n;i++){
        int B = OR(i-1, i), C = AND(i-1, i);
        a[i] = C;
        for(int j=0;j<30;j++) if(((1 << j) & B) && !((1 << j) & a[i-1])) a[i] += (1 << j);
    }

    sort(a+1, a+1+n);
    answer(a[k]);
}