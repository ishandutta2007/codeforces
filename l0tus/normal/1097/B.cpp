#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int MN =1e5;

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N,A[20];
    bool ispos = false;
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<(1<<N); i++){
        int sum = 0;
        for(int j=0; j<N; j++){
            if(i & (1<<j)) sum += A[j];
            else sum += 360-A[j];
        }
        if(sum%360==0) ispos =true;
    }
    if(ispos) cout << "YES";
    else cout << "NO";

}