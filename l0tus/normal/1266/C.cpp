#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5+5;
int R,C,ans;


int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> R >> C;
    if(R>=2&&C>=2){
        for(int j=1; j<=R; j++){
            for(int i=R+1; i<=R+C; i++)
                cout << i*j << ' ';
            cout << '\n';
        }
    }
    else if(R==1&&C==1) cout << 0;
    else{
        if(R==1) for(int i=2; i<=C+1; i++) cout << i << ' ';
        if(C==1) for(int i=2; i<=R+1; i++) cout << i << '\n';
    }
}