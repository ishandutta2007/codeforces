#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int A[26][MN],D[26][MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    string S;
    cin >> S;
    for(int i=0; i<S.size(); i++) A[S[i]-'a'][i] = 1;
    for(int i=0; i<S.size(); i++){
        for(int j=0; j<26; j++) D[j][i+1] = A[j][i] + D[j][i];
    }
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int l,r,cnt=0;
        cin >> l >> r;
        for(int j=0; j<26; j++) if(D[j][r]-D[j][l-1]) cnt++;
        if(l==r) cout << "Yes\n";
        else if(S[l-1]==S[r-1]&&cnt<=2) cout << "No\n";
        else cout << "Yes\n";
    }
}