#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool isPrime(int a){
    if (a <= 1) return false;
    for (int i = 2; i * i <= a; ++i)
        if (a % i == 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a; cin >> a;
    if (isPrime(a))
        cout << 1 << endl << a << endl;
    else{
        if (isPrime(a - 2))
            cout << 2 << endl << 2 << " " << a - 2 << endl;
        else{
            for (int i = 1; ; ++i){
                if (isPrime(a - i)){
                    for (int j = 2; 2 * j <= i; ++j){
                        if (isPrime(j) && isPrime(i - j))
                        {
                            cout << 3 << endl;
                            cout << a - i << " " << j << " " << i - j << endl;
                            exit(0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}