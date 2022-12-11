#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+5;
int A,B,C,x;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int Q;
    cin >> Q;
    while(Q--){
        cin >> A >> B;
        if(A<B) swap(A,B);
        C = A-B;
        x = 0;
        for(int i=0; i<=100000; i++){
            x += i;
            if(x%2==C%2&&C<=x){
                cout << i << '\n';
                break;
            }
        }
    }
}