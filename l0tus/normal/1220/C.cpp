#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int m = 300;
string S;
int main()
{
    cin >> S;
    for(int i=0; i<S.size(); i++){
        m = min(m,(int)S[i]);
        if(m<(int)S[i]) cout << "Ann\n";
        else cout << "Mike\n";
    }
}