//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 1000 * 100 + 100;

int a[maxN];
bool win[maxN]; 
int p[maxN];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) { 
        cin >> a[i];
        p[a[i]] = i;
    }

    for(int i = n ; i > 0; i-- ) {
        int x = p[i];
        for(int j = x + i ; j < n; j+=i )
            if( a[j] > i )
                win[x] |= !win[j];
        for(int j = x - i ; j >= 0; j-=i )
            if( a[j] > i )
                win[x] |= !win[j];
    }

    for(int i = 0; i < n; i++)
        cout << (win[i]? "A" : "B" ) ;
    cout << endl;
}